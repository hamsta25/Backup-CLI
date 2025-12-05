# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Planned
- Full file copying in snapshots
- Checksum verification
- Progress bars for long operations
- Exclude patterns support
- Comprehensive test suite
- CI/CD pipeline

## [1.0.0] - 2025-12-05

### Added
- Initial release of Backup-CLI
- Python implementation with standard library only
- C implementation for high performance
- Cross-platform support (Windows, macOS, Linux)
- OS integrity checking
- Directory and file scanning
- Snapshot creation with metadata
- Command-line interface with argparse (Python) and manual parsing (C)
- Help and version information
- Python package setup (setup.py, pyproject.toml)
- C build system (Makefile, CMakeLists.txt)
- Comprehensive documentation:
  - README.md with installation and usage instructions
  - REQUIREMENTS.md (functional requirements)
  - NON_FUNCTIONAL_REQUIREMENTS.md
  - DOCUMENTATION.md (developer documentation)
  - ROADMAP.md (project roadmap and future plans)
  - TASKS.md (task tracking and TODO lists)
  - INSTALL.md (detailed installation guide)
- Build scripts for automated building (build.sh, build.bat)
- License (MIT)
- .gitignore for Python and C artifacts

### Features
- Backup snapshots with timestamps
- Metadata generation (JSON for Python, text for C)
- Multi-platform path handling
- Error handling and user-friendly messages
- Console script entry points for easy command-line access

### Documentation
- Complete README with badges and examples
- Installation instructions for all platforms
- Usage examples and command-line options
- Developer documentation with API reference
- Project roadmap with version plans
- Branching strategy documentation
- Task tracking system

### Technical Details
- Python: Requires 3.7+, no external dependencies
- C: Standard C99, compiles with GCC, Clang, MSVC
- Package managers: pip (Python), make/cmake (C)
- Supports installation from source, PyPI (future), and binary distributions

## [0.1.0] - 2025-12-05

### Added
- Initial project structure
- Basic README

---

## Version History

### Version 1.0.0 (Current)
- Complete implementation with Python and C versions
- Full documentation suite
- Ready for public release
- Tested on Linux (primary development platform)

### Version 0.1.0
- Project initialization
- Repository setup

---

## Notes

### Known Limitations in v1.0.0
- Snapshot creation only creates directory structure (no file copying yet)
- Verification flag is accepted but not fully implemented
- No incremental backup support
- No compression or encryption
- Limited to creating snapshots, not full backups yet

### Future Enhancements
See [ROADMAP.md](ROADMAP.md) for detailed plans.

---

[Unreleased]: https://github.com/hamsta25/Backup-CLI/compare/v1.0.0...HEAD
[1.0.0]: https://github.com/hamsta25/Backup-CLI/releases/tag/v1.0.0
[0.1.0]: https://github.com/hamsta25/Backup-CLI/releases/tag/v0.1.0
