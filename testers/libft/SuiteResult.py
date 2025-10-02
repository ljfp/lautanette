from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional


@dataclass
class SuiteResult:
    """Aggregated outcome for a single Lautanette libft test suite."""

    suite_name: str
    failed_functions: List[str] = field(default_factory=list)
    log_files: List[Path] = field(default_factory=list)
    notes: List[str] = field(default_factory=list)
    metadata: Dict[str, Optional[str]] = field(default_factory=dict)

    def extend_notes(self, *messages: str) -> None:
        for message in messages:
            if message:
                self.notes.append(message)

    @property
    def has_failures(self) -> bool:
        return bool(self.failed_functions)

    def as_summary_dict(self) -> Dict[str, object]:
        return {
            "suite": self.suite_name,
            "failed_functions": self.failed_functions,
            "log_files": [str(path) for path in self.log_files],
            "notes": self.notes,
            "metadata": self.metadata,
        }
