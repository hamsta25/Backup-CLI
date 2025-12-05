# Backup-CLI Developer Documentation

## Table of Contents
1. [Architecture Overview](#architecture-overview)
2. [Code Structure](#code-structure)
3. [Building and Installing](#building-and-installing)
4. [Development Guidelines](#development-guidelines)
5. [API Reference](#api-reference)
6. [Testing](#testing)
7. [Contributing](#contributing)

## Architecture Overview

Backup-CLI is designed as a simple, efficient backup tool with two implementations:
- **Python Implementation**: Provides cross-platform compatibility with easy installation via pip
- **C Implementation**: Offers high performance and minimal dependencies

### Design Principles
- **Simplicity**: Keep the codebase simple and maintainable
- **Cross-platform**: Support Windows, macOS, and Linux
- **Minimal dependencies**: Avoid external dependencies where possible
- **Modularity**: Design components that can be extended or replaced

### High-Level Architecture

```
┌─────────────────────────────────────────┐
│         Command-Line Interface          │
│      (Argument parsing, help text)      │
└────────────────┬────────────────────────┘
                 │
                 ▼
┌─────────────────────────────────────────┐
│          Backup Controller              │
│    (Orchestrates backup operations)     │
└────────────────┬────────────────────────┘
                 │
         ┌───────┴───────┐
         ▼               ▼
┌─────────────────┐ ┌─────────────────┐
│  OS Integrity   │ │  File Scanner   │
│    Checker      │ │                 │
└─────────────────┘ └─────────────────┘
         │               │
         └───────┬───────┘
                 ▼
         ┌────────────────┐
         │    Snapshot    │
         │    Creator     │
         └────────────────┘
```

## Code Structure

### Python Implementation

```
backup_cli.py           # Main Python implementation
__init__.py            # Package initialization
setup.py               # setuptools configuration
pyproject.toml         # Modern Python packaging
requirements.txt       # Dependencies (currently empty)
```

#### Key Classes and Functions

**BackupCLI Class**
- `__init__()`: Initialize backup CLI with OS detection
- `check_os_integrity()`: Verify operating system information
- `scan_directories(path)`: Recursively scan directories and count files
- `calculate_checksum(filepath)`: Calculate file checksums (SHA-256)
- `create_snapshot(source, dest)`: Create backup snapshot with metadata
- `perform_backup(source, dest, verify)`: Orchestrate the complete backup process

**main() Function**
- Parse command-line arguments using argparse
- Create BackupCLI instance
- Execute backup operation

### C Implementation

```
backup_cli.c           # Main C implementation
Makefile               # Build configuration for make
CMakeLists.txt         # Build configuration for CMake
```

#### Key Functions

- `print_usage()`: Display help information
- `print_version()`: Show version information
- `get_timestamp()`: Get current timestamp string
- `check_os_integrity()`: Verify OS information
- `create_directory_recursive()`: Create directory with parent directories
- `create_snapshot()`: Create backup snapshot
- `perform_backup()`: Execute backup operation
- `main()`: Entry point with argument parsing

## Building and Installing

### Python Version

#### Install from Source
```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Install in development mode
pip install -e .

# Or install normally
pip install .
```

#### Install from PyPI (when published)
```bash
pip install backup-cli
```

#### Build Distribution Packages
```bash
# Build wheel and source distribution
python setup.py sdist bdist_wheel

# Or using build
pip install build
python -m build
```

### C Version

#### Using Make (Linux/macOS)
```bash
# Build
make

# Install (requires sudo)
sudo make install

# Uninstall
sudo make uninstall

# Clean
make clean
```

#### Using Make (Windows with MinGW)
```bash
# Build
mingw32-make

# Clean
mingw32-make clean
```

#### Using CMake (All Platforms)
```bash
# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build
cmake --build .

# Install (may require sudo on Unix)
cmake --install .

# Create packages
cpack
```

#### Manual Compilation
```bash
# Linux/macOS
gcc -Wall -Wextra -O2 -o backup-cli backup_cli.c

# Windows (MSVC)
cl /W4 /O2 backup_cli.c /Fe:backup-cli.exe

# Windows (MinGW)
gcc -Wall -Wextra -O2 -o backup-cli.exe backup_cli.c
```

## Development Guidelines

### Python Code Style
- Follow PEP 8 style guidelines
- Use type hints where appropriate
- Maximum line length: 100 characters
- Use descriptive variable names
- Add docstrings to all classes and functions

### C Code Style
- Use K&R or Allman style bracing
- Maximum line length: 100 characters
- Use descriptive variable names
- Comment complex logic
- Avoid compiler-specific extensions

### Git Workflow
1. Create a feature branch from `main`
2. Make changes with clear commit messages
3. Test thoroughly on target platforms
4. Submit pull request with description
5. Address review comments
6. Merge when approved

### Commit Message Format
```
type: subject

body

footer
```

Types: feat, fix, docs, style, refactor, test, chore

### Testing Best Practices
- Test on all target platforms before release
- Test with various file systems and permissions
- Test error conditions and edge cases
- Verify installation methods work correctly

## API Reference

### Python API

#### BackupCLI Class

```python
class BackupCLI:
    def __init__(self)
        """Initialize BackupCLI instance"""
    
    def check_os_integrity(self) -> bool
        """Check OS integrity. Returns True if successful."""
    
    def scan_directories(self, path: str) -> tuple[int, int]
        """Scan directories recursively. Returns (dir_count, file_count)."""
    
    def calculate_checksum(self, filepath: str, algorithm: str = 'sha256') -> Optional[str]
        """Calculate file checksum. Returns hex digest or None on error."""
    
    def create_snapshot(self, source_path: str, backup_path: str) -> Optional[str]
        """Create backup snapshot. Returns snapshot path or None on error."""
    
    def perform_backup(self, source: str, destination: str, verify: bool = True) -> bool
        """Perform complete backup operation. Returns True if successful."""
```

#### Command-Line Arguments

```
--source, -s <path>    Source directory (default: current directory)
--dest, -d <path>      Destination directory (required)
--verify, -v           Enable verification (not fully implemented)
--version              Show version information
--help, -h             Show help message
```

### C API

#### Command-Line Arguments

```
--source, -s <path>    Source directory (default: current directory)
--dest, -d <path>      Destination directory (required)
--verify, -v           Enable verification (not fully implemented)
--version              Show version information
--help, -h             Show help message
```

## Testing

### Manual Testing

#### Test Basic Functionality
```bash
# Python version
backup-cli --source /path/to/source --dest /path/to/backup

# C version
./backup-cli --source /path/to/source --dest /path/to/backup
```

#### Test Help and Version
```bash
backup-cli --help
backup-cli --version
```

#### Test Error Handling
```bash
# Missing required argument
backup-cli --source /path/to/source

# Invalid paths
backup-cli --source /nonexistent --dest /backup
```

### Automated Testing (Future)

```bash
# Python tests
pytest tests/

# C tests (when implemented)
make test
```

## Contributing

### How to Contribute

1. **Fork the Repository**
   - Fork on GitHub
   - Clone your fork locally

2. **Create a Branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make Changes**
   - Follow coding guidelines
   - Add tests if applicable
   - Update documentation

4. **Test Your Changes**
   - Test on multiple platforms if possible
   - Ensure all existing functionality still works

5. **Commit Your Changes**
   ```bash
   git commit -m "feat: add your feature"
   ```

6. **Push to Your Fork**
   ```bash
   git push origin feature/your-feature-name
   ```

7. **Submit a Pull Request**
   - Describe your changes
   - Reference any related issues
   - Wait for review

### Code Review Process

- All changes require review before merging
- Reviewers will check for:
  - Code quality and style
  - Test coverage
  - Documentation updates
  - Cross-platform compatibility

### Issue Reporting

When reporting issues, please include:
- Operating system and version
- Python/C version
- Steps to reproduce
- Expected behavior
- Actual behavior
- Error messages or logs

## Troubleshooting

### Common Issues

#### Python: ModuleNotFoundError
- Ensure package is installed: `pip install -e .`
- Check Python version: `python --version` (must be 3.7+)

#### C: Compilation Errors
- Install build tools (gcc, make, cmake)
- Check compiler version compatibility
- Verify system libraries are available

#### Permission Errors
- Run with appropriate permissions
- Check source/destination permissions
- Use sudo/administrator as needed

#### Path Issues
- Use absolute paths when possible
- Check path separators for your OS
- Verify paths exist before running

## Release Process

1. Update version numbers in:
   - `backup_cli.py`
   - `setup.py`
   - `pyproject.toml`
   - `backup_cli.c`
   - `CMakeLists.txt`

2. Update CHANGELOG.md

3. Create release branch
   ```bash
   git checkout -b release/v1.0.0
   ```

4. Test thoroughly on all platforms

5. Create Git tag
   ```bash
   git tag -a v1.0.0 -m "Release version 1.0.0"
   git push origin v1.0.0
   ```

6. Build and publish packages
   ```bash
   # Python
   python -m build
   twine upload dist/*
   
   # C packages
   cpack
   ```

7. Create GitHub release with:
   - Release notes
   - Binary packages
   - Source archives

## License

MIT License - See LICENSE file for details.

## Support

- GitHub Issues: https://github.com/hamsta25/Backup-CLI/issues
- Documentation: https://github.com/hamsta25/Backup-CLI/blob/main/DOCUMENTATION.md
