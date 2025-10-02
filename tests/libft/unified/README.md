# Unified libft test assets

This directory is intentionally minimal. The actual test sources live under
`tests/libft/{fsoares,Tripouille,alelievr,war-machine}`. The unified runner
copies those suites into the temporary workspace and orchestrates them from a
single entry point.

Generated artifacts such as `unified_summary.json` are written next to this
README inside the temporary execution directory.
