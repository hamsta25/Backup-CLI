# Backup-CLI 🔄

A powerful and simple command-line interface for system backups that works across Windows, macOS, and Linux. Available in both Python and C implementations.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Python Version](https://img.shields.io/badge/python-3.7+-blue.svg)](https://www.python.org/downloads/)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg)](https://github.com/hamsta25/Backup-CLI)

## 🌟 Features

- ✅ **Cross-Platform**: Works on Windows, macOS, and Linux
- ✅ **Dual Implementation**: Available in Python and C
- ✅ **OS Integrity Check**: Verifies operating system before backup
- ✅ **Directory Scanning**: Recursively scans directories and files
- ✅ **Snapshot Creation**: Creates timestamped snapshots with metadata
- ✅ **Easy Installation**: Install via pip or compile from source
- ✅ **No Dependencies**: Python version uses standard library only
- ✅ **Command-Line Interface**: Simple and intuitive CLI

## 📋 Table of Contents

- [Quick Start](#-quick-start)
- [Installation](#-installation)
  - [Python Version](#python-version-recommended)
  - [C Version](#c-version)
- [Usage](#-usage)
- [Documentation](#-documentation)
- [Development](#-development)
- [Project Structure](#-project-structure)
- [Roadmap](#-roadmap)
- [Contributing](#-contributing)
- [License](#-license)

## 🚀 Quick Start

### Using Python (Recommended for Most Users)

```bash
# Install via pip
pip install git+https://github.com/hamsta25/Backup-CLI.git

# Run backup
backup-cli --source /path/to/backup --dest /path/to/destination
```

### Using C (For Performance-Critical Scenarios)

```bash
# Clone and compile
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI
make

# Run backup
./backup-cli --source /path/to/backup --dest /path/to/destination
```

## 📦 Installation

### Python Version (Recommended)

The Python version is the easiest to install and works on all platforms.

#### Method 1: Install from PyPI (Coming Soon)

```bash
pip install backup-cli
```

#### Method 2: Install from Source

```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Install using pip
pip install .

# Or install in development mode
pip install -e .
```

#### Method 3: Direct Installation from GitHub

```bash
pip install git+https://github.com/hamsta25/Backup-CLI.git
```

#### Requirements
- Python 3.7 or higher
- pip (usually comes with Python)
- No external dependencies required!

### C Version

The C version offers high performance and minimal dependencies.

#### Method 1: Using Make (Linux/macOS/Windows with MinGW)

```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Build
make

# Install (Linux/macOS - requires sudo)
sudo make install

# Or just run directly
./backup-cli --help
```

#### Method 2: Using CMake (All Platforms)

```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build .

# Install (may require sudo on Unix-like systems)
cmake --install .

# Create distribution packages
cpack
```

#### Method 3: Manual Compilation

**Linux/macOS:**
```bash
gcc -Wall -Wextra -O2 -o backup-cli backup_cli.c
```

**Windows (MSVC):**
```cmd
cl /W4 /O2 backup_cli.c /Fe:backup-cli.exe
```

**Windows (MinGW):**
```cmd
gcc -Wall -Wextra -O2 -o backup-cli.exe backup_cli.c
```

#### Requirements
- GCC, Clang, or MSVC compiler
- Make (for Makefile method)
- CMake 3.10+ (for CMake method)
- No external libraries required!

### Download Pre-built Binaries

Pre-built binaries will be available in the [Releases](https://github.com/hamsta25/Backup-CLI/releases) section:

- **Windows**: `backup-cli-windows-x64.zip`
- **macOS**: `backup-cli-macos.zip`
- **Linux**: `backup-cli-linux-x64.tar.gz`

Simply download, extract, and run!

## 💻 Usage

### Basic Usage

```bash
# Backup current directory to destination
backup-cli --dest /backup/location

# Backup specific source to destination
backup-cli --source /home/user/documents --dest /backup/documents

# Backup with verification (future feature)
backup-cli --source /data --dest /backup/data --verify
```

### Command-Line Options

```
Usage: backup-cli [OPTIONS]

Options:
  -s, --source <path>      Source directory to backup (default: current directory)
  -d, --dest <path>        Destination directory for backup (required)
  -v, --verify             Verify backup integrity after completion
  -h, --help               Show help message and exit
  --version                Show version information and exit
```

### Examples

#### Example 1: Backup Home Directory (Linux/macOS)
```bash
backup-cli --source /home/username --dest /mnt/backup/home
```

#### Example 2: Backup User Folder (Windows)
```cmd
backup-cli --source C:\Users\Username --dest D:\Backups
```

#### Example 3: Backup with Relative Paths
```bash
backup-cli --source ./myproject --dest ../backups
```

#### Example 4: Using Short Options
```bash
backup-cli -s /data -d /backup/data -v
```

### Output Example

```
==================================================
Starting Backup Operation
==================================================
Checking OS integrity for Linux...
Platform: Linux-5.15.0-76-generic-x86_64-with-glibc2.35
Architecture: x86_64
Python version: 3.10.6
OS integrity check completed.

Scanning directory: /home/user/documents
Found 15 directories and 127 files

Creating snapshot: backup_Linux_20251205_143022
Source: /home/user/documents
Destination: /backup/documents/backup_Linux_20251205_143022
Snapshot created successfully at: /backup/documents/backup_Linux_20251205_143022

==================================================
Backup completed successfully!
==================================================
```

## 📚 Documentation

Comprehensive documentation is available in the repository:

- **[REQUIREMENTS.md](REQUIREMENTS.md)** - Functional requirements
- **[NON_FUNCTIONAL_REQUIREMENTS.md](NON_FUNCTIONAL_REQUIREMENTS.md)** - Non-functional requirements
- **[DOCUMENTATION.md](DOCUMENTATION.md)** - Developer documentation and API reference
- **[ROADMAP.md](ROADMAP.md)** - Project roadmap and future plans
- **[TASKS.md](TASKS.md)** - Task tracking and TODO lists

## 🛠️ Development

### Setting Up Development Environment

#### Python Development

```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Install in development mode
pip install -e .

# Make changes to backup_cli.py
# Test your changes
backup-cli --help
```

#### C Development

```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Make changes to backup_cli.c
# Compile
make

# Test
./backup-cli --help
```

### Running Tests

```bash
# Python tests (when available)
pytest tests/

# C tests (when available)
make test
```

### Code Style

- **Python**: Follow PEP 8 guidelines
- **C**: Use consistent K&R or Allman style

## 📁 Project Structure

```
Backup-CLI/
├── backup_cli.py              # Python implementation
├── backup_cli.c               # C implementation
├── __init__.py                # Python package init
├── setup.py                   # Python package setup (setuptools)
├── pyproject.toml             # Modern Python packaging
├── requirements.txt           # Python dependencies (empty - no deps!)
├── Makefile                   # Build file for make
├── CMakeLists.txt             # Build file for CMake
├── README.md                  # This file
├── REQUIREMENTS.md            # Functional requirements
├── NON_FUNCTIONAL_REQUIREMENTS.md  # Non-functional requirements
├── DOCUMENTATION.md           # Developer documentation
├── ROADMAP.md                 # Project roadmap
├── TASKS.md                   # Task tracking
└── LICENSE                    # MIT License
```

## 🗺️ Roadmap

### Version 1.0.0 (Current)
- ✅ Basic backup functionality
- ✅ Cross-platform support
- ✅ Python and C implementations
- ✅ Package distribution setup

### Version 1.1.0 (Q1 2026)
- 🔲 Full file copying in snapshots
- 🔲 Checksum verification
- 🔲 Progress bars
- 🔲 Exclude patterns
- 🔲 Comprehensive testing

### Version 1.2.0 (Q2 2026)
- 🔲 Incremental backups
- 🔲 Differential backups
- 🔲 Backup versioning

### Version 2.0.0 (Q4 2026)
- 🔲 Restore functionality
- 🔲 Compression support
- 🔲 Encryption support
- 🔲 Scheduled backups

See [ROADMAP.md](ROADMAP.md) for detailed plans.

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch** (`git checkout -b feature/amazing-feature`)
3. **Make your changes**
4. **Test thoroughly** on multiple platforms if possible
5. **Commit your changes** (`git commit -m 'Add amazing feature'`)
6. **Push to the branch** (`git push origin feature/amazing-feature`)
7. **Open a Pull Request**

Please read our [DOCUMENTATION.md](DOCUMENTATION.md) for development guidelines.

### Areas for Contribution

- 🐛 Bug fixes
- ✨ New features
- 📝 Documentation improvements
- 🧪 Test coverage
- 🌐 Platform-specific optimizations
- 🎨 UI/UX improvements

## 🔒 Security

For security concerns, please open an issue or contact the maintainers directly.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👥 Authors

- **Backup-CLI Team** - [GitHub](https://github.com/hamsta25/Backup-CLI)

## 🙏 Acknowledgments

- Thanks to all contributors who help improve this project
- Inspired by the need for simple, cross-platform backup solutions
- Built with standard tools and libraries for maximum compatibility

## 📞 Support

- **Issues**: [GitHub Issues](https://github.com/hamsta25/Backup-CLI/issues)
- **Documentation**: [Project Documentation](DOCUMENTATION.md)
- **Roadmap**: [Project Roadmap](ROADMAP.md)

## 🌟 Star History

If you find this project useful, please consider giving it a star on GitHub!

---

**Made with ❤️ for the open-source community**
