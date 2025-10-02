from __future__ import annotations

import json
import logging
import os
import shutil
from pathlib import Path
from typing import Iterable, List, Type

from halo import Halo

from testers.libft.Fsoares import Fsoares
from testers.libft.SuiteResult import SuiteResult
from utils.TerminalColors import TC
from utils.ExecutionContext import is_strict

logger = logging.getLogger("libft-unified")


class Unified:

    name = "unified"
    folder = name
    git_url = "Lautanette integrated suite"

    def __init__(self, tests_dir, temp_dir, to_execute, missing) -> None:
        self.tests_root = Path(tests_dir)
        self.temp_root = Path(temp_dir)
        self.temp_dir = self.temp_root / self.folder
        self.to_execute = list(to_execute)
        self.missing = list(missing)
        self.library = self.temp_root / "libft.a"
        self.header = self.temp_root / "libft.h"
        self.report_path = self.temp_dir / "unified_summary.json"
        self._compat_note: List[str] = []

    # region orchestration
    def execute(self):
        suite_classes = self._resolve_suites()
        if is_strict():
            suite_classes = [cls for cls in suite_classes if cls is Fsoares]
        self._prepare_frameworks(suite_classes)
        suites = [cls(self.tests_root, self.temp_root, self.to_execute, self.missing) for cls in suite_classes]

        results: List[SuiteResult] = []
        with Halo(text=f"{TC.CYAN}Running Lautanette libft suites{TC.NC}") as spinner:
            for suite in suites:
                logger.info("Executing suite %s", suite.name)
                try:
                    result = suite.execute()
                except Exception as exc:
                    spinner.fail()
                    logger.exception("Suite %s crashed", suite.name)
                    crash_result = SuiteResult(suite.name)
                    crash_result.extend_notes(
                        f"Suite crashed with {exc.__class__.__name__}: {exc}")
                    results.append(crash_result)
                    continue
                results.append(result)
            spinner.succeed()

        text_report = self._write_summary(results)
        failed = sorted({func for res in results for func in res.failed_functions})
        if failed:
            print(
                f"\n{TC.B_RED}Unified summary{TC.NC}: fail on {', '.join(failed)}\n"
                f"See {TC.B_WHITE}{self.report_path}{TC.NC} for details."
            )
        else:
            print(
                f"\n{TC.B_GREEN}Unified summary{TC.NC}: all suites passed. "
                f"Details in {TC.B_WHITE}{self.report_path}{TC.NC}."
            )
        notes = []
        for suite in results:
            status = "OK" if not suite.failed_functions else f"KO ({', '.join(suite.failed_functions)})"
            notes.append(f"{suite.suite_name}: {status}")
        if is_strict():
            notes.append("Strict mode limited execution to sanitizer-heavy tests.")
        if self._compat_note:
            notes.extend(self._compat_note)
        log_files = [self.report_path, text_report]
        for suite in results:
            for path in suite.log_files:
                if path not in log_files:
                    log_files.append(path)
        return SuiteResult(
            self.name,
            failed,
            log_files=log_files,
            notes=notes,
            metadata={"suites": len(results)}
        )

    # endregion

    def _resolve_suites(self) -> List[Type]:
        suites: List[Type] = [Fsoares]
        compat_flag = os.getenv("LAUTANETTE_ENABLE_COMPAT_SUITES", "").strip().lower()
        if compat_flag in {"1", "true", "yes"}:
            self._compat_note.append(
                "Compatibility suites enabled via LAUTANETTE_ENABLE_COMPAT_SUITES."
            )
            try:
                from testers.libft.Alelievr import Alelievr
                from testers.libft.Tripouille import Tripouille
                from testers.libft.WarMachine import WarMachine
            except Exception as exc:
                logger.warning("Failed to load compatibility suites: %s", exc)
            else:
                suites.extend([Tripouille, Alelievr, WarMachine])
        return suites

    def _prepare_frameworks(self, suite_classes: Iterable[Type]) -> None:
        self.temp_dir.mkdir(parents=True, exist_ok=True)
        for suite_cls in suite_classes:
            self._copy_suite_assets(suite_cls)

    def _copy_suite_assets(self, suite_cls) -> None:
        destination = self.temp_root / suite_cls.folder
        if destination.exists():
            shutil.rmtree(destination)
        source = self.tests_root / suite_cls.folder
        shutil.copytree(source, destination)
        if self.library.exists():
            shutil.copy(self.library, destination)
        else:
            logger.warning("Library %s not found when preparing %s", self.library, suite_cls.name)
        if self.header.exists():
            shutil.copy(self.header, destination)
        else:
            logger.warning("Header %s not found when preparing %s", self.header, suite_cls.name)

    def _write_summary(self, suites: Iterable[SuiteResult]) -> Path:
        suite_list = list(suites)
        self.temp_dir.mkdir(parents=True, exist_ok=True)
        data = [suite.as_summary_dict() for suite in suite_list]
        self.report_path.write_text(json.dumps(data, indent=2))

        lines: List[str] = []
        for suite in suite_list:
            lines.append(f"Suite: {suite.suite_name}")
            if suite.failed_functions:
                lines.append(f"  Failed: {', '.join(suite.failed_functions)}")
            else:
                lines.append("  Failed: none")
            for note in suite.notes:
                lines.append(f"  Note: {note}")
            for log in suite.log_files:
                lines.append(f"  Log: {log}")
            lines.append("")
        text_path = self.temp_dir / "unified_summary.txt"
        text_path.write_text("\n".join(lines))
        return text_path