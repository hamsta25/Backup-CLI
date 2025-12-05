# Installation Guide

Complete installation instructions for Backup-CLI on all supported platforms.

## Table of Contents
- [Python Version](#python-version)
  - [Windows](#windows-python)
  - [macOS](#macos-python)
  - [Linux](#linux-python)
- [C Version](#c-version)
  - [Windows](#windows-c)
  - [macOS](#macos-c)
  - [Linux](#linux-c)
- [Verification](#verification)
- [Troubleshooting](#troubleshooting)

---

## Python Version

### Windows (Python)

#### Prerequisites
- Python 3.7 or higher ([Download Python](https://www.python.org/downloads/))
- pip (included with Python)

#### Installation Methods

**Method 1: Install from GitHub**
```cmd
pip install git+https://github.com/hamsta25/Backup-CLI.git
```

**Method 2: Install from Source**
```cmd
# Download and extract the repository or clone with Git
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Install
pip install .
```

**Method 3: Direct Download**
1. Download the source code from [GitHub](https://github.com/hamsta25/Backup-CLI)
2. Extract the ZIP file
3. Open Command Prompt in the extracted folder
4. Run: `pip install .`

#### Verify Installation
```cmd
backup-cli --version
backup-cli --help
```

---

### macOS (Python)

#### Prerequisites
- Python 3.7 or higher (usually pre-installed, or use [Homebrew](https://brew.sh/))
- pip

#### Installation Methods

**Method 1: Install from GitHub**
```bash
pip3 install git+https://github.com/hamsta25/Backup-CLI.git
```

**Method 2: Install from Source**
```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Install
pip3 install .
```

**Method 3: Using Homebrew (Future)**
```bash
brew tap hamsta25/backup-cli
brew install backup-cli
```

#### Verify Installation
```bash
backup-cli --version
backup-cli --help
```

---

### Linux (Python)

#### Prerequisites
- Python 3.7 or higher
- pip

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install python3 python3-pip
```

**Fedora/RHEL/CentOS:**
```bash
sudo dnf install python3 python3-pip
```

**Arch Linux:**
```bash
sudo pacman -S python python-pip
```

#### Installation Methods

**Method 1: Install from GitHub**
```bash
pip3 install --user git+https://github.com/hamsta25/Backup-CLI.git
```

**Method 2: Install from Source**
```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Install for current user
pip3 install --user .

# Or install system-wide (requires sudo)
sudo pip3 install .
```

**Method 3: Using Package Manager (Future)**
```bash
# Ubuntu/Debian
sudo apt install backup-cli

# Fedora
sudo dnf install backup-cli

# Arch Linux (AUR)
yay -S backup-cli
```

#### Verify Installation
```bash
backup-cli --version
backup-cli --help
```

---

## C Version

### Windows (C)

#### Prerequisites
- C compiler (one of the following):
  - MinGW-w64 ([Download](https://www.mingw-w64.org/))
  - Microsoft Visual Studio (Community Edition is free)
  - TDM-GCC ([Download](https://jmeubank.github.io/tdm-gcc/))

#### Installation Methods

**Method 1: Download Pre-built Binary**
1. Go to [Releases](https://github.com/hamsta25/Backup-CLI/releases)
2. Download `backup-cli-Windows.zip`
3. Extract to a folder (e.g., `C:\Program Files\Backup-CLI`)
4. Add the folder to your PATH environment variable
5. Run: `backup-cli --help`

**Method 2: Compile from Source (MinGW)**
```cmd
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Build
mingw32-make

# Run
backup-cli.exe --help
```

**Method 3: Compile from Source (MSVC)**
```cmd
# Open Developer Command Prompt for Visual Studio
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Build
cl /W4 /O2 backup_cli.c /Fe:backup-cli.exe

# Run
backup-cli.exe --help
```

**Method 4: Using CMake**
```cmd
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Build
mkdir build
cd build
cmake ..
cmake --build .

# Run
backup-cli.exe --help
```

---

### macOS (C)

#### Prerequisites
- Xcode Command Line Tools
```bash
xcode-select --install
```

#### Installation Methods

**Method 1: Download Pre-built Binary**
1. Go to [Releases](https://github.com/hamsta25/Backup-CLI/releases)
2. Download `backup-cli-macOS.zip`
3. Extract: `unzip backup-cli-macOS.zip`
4. Make executable: `chmod +x backup-cli-macOS/backup-cli`
5. Run: `./backup-cli-macOS/backup-cli --help`

**Method 2: Compile from Source (Make)**
```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Build
make

# Install (optional)
sudo make install

# Run
./backup-cli --help
# Or if installed: backup-cli --help
```

**Method 3: Using CMake**
```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Build
mkdir build
cd build
cmake ..
cmake --build .

# Install (optional)
sudo cmake --install .

# Run
./backup-cli --help
```

**Method 4: Using Homebrew (Future)**
```bash
brew tap hamsta25/backup-cli
brew install backup-cli
```

---

### Linux (C)

#### Prerequisites

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install build-essential gcc make cmake
```

**Fedora/RHEL/CentOS:**
```bash
sudo dnf groupinstall "Development Tools"
sudo dnf install gcc make cmake
```

**Arch Linux:**
```bash
sudo pacman -S base-devel gcc make cmake
```

#### Installation Methods

**Method 1: Download Pre-built Binary**
1. Go to [Releases](https://github.com/hamsta25/Backup-CLI/releases)
2. Download `backup-cli-Linux.tar.gz`
3. Extract: `tar xzf backup-cli-Linux.tar.gz`
4. Make executable: `chmod +x backup-cli-Linux/backup-cli`
5. Run: `./backup-cli-Linux/backup-cli --help`

**Method 2: Compile from Source (Make)**
```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Build
make

# Install (optional)
sudo make install

# Run
./backup-cli --help
# Or if installed: backup-cli --help
```

**Method 3: Using CMake**
```bash
# Clone the repository
git clone https://github.com/hamsta25/Backup-CLI.git
cd Backup-CLI

# Build
mkdir build
cd build
cmake ..
cmake --build .

# Install (optional)
sudo cmake --install .

# Create packages (optional)
cpack

# Run
./backup-cli --help
```

**Method 4: Using Package Manager (Future)**
```bash
# Ubuntu/Debian
sudo apt install backup-cli

# Fedora
sudo dnf install backup-cli

# Arch Linux (AUR)
yay -S backup-cli-c
```

---

## Verification

After installation, verify that Backup-CLI is working:

```bash
# Check version
backup-cli --version

# Expected output: Backup-CLI version 1.0.0

# Check help
backup-cli --help

# Expected output: Usage information and options

# Test run (creates snapshot directory)
backup-cli --source . --dest /tmp/test-backup
```

---

## Troubleshooting

### Python Version Issues

**Issue: `backup-cli: command not found`**
- Solution: Add Python's scripts directory to PATH
  - Windows: `C:\Users\<Username>\AppData\Local\Programs\Python\Python3X\Scripts`
  - macOS/Linux: `~/.local/bin`

**Issue: `ModuleNotFoundError`**
- Solution: Reinstall with `pip install --force-reinstall backup-cli`

**Issue: `Permission denied`**
- Solution (Linux/macOS): Use `pip install --user` or `sudo pip install`

### C Version Issues

**Issue: `gcc: command not found`**
- Solution: Install build tools (see prerequisites for your platform)

**Issue: `make: command not found`**
- Solution: Install make (usually part of build-essential or development tools)

**Issue: `Permission denied` when installing**
- Solution: Use `sudo make install` on Unix-like systems

**Issue: Compilation errors on Windows**
- Solution: Ensure MinGW or MSVC is properly installed and in PATH

### General Issues

**Issue: Cannot create backup directory**
- Check destination path exists and you have write permissions
- Try a different destination path

**Issue: Permission errors during backup**
- Run with administrator/sudo if backing up system directories
- Or backup user directories only

**Issue: Out of disk space**
- Verify destination has sufficient free space
- Use a different destination with more space

### Getting Help

If you encounter issues not covered here:
1. Check the [DOCUMENTATION.md](DOCUMENTATION.md)
2. Search [GitHub Issues](https://github.com/hamsta25/Backup-CLI/issues)
3. Open a new issue with:
   - Your operating system and version
   - Python/C compiler version
   - Complete error message
   - Steps to reproduce

---

## Uninstallation

### Python Version

```bash
pip uninstall backup-cli
```

### C Version

**If installed with `make install`:**
```bash
sudo make uninstall
```

**If installed manually:**
```bash
# Remove the binary from your PATH location
# Linux/macOS
sudo rm /usr/local/bin/backup-cli

# Windows: Delete from installation directory
```

---

## Next Steps

After installation, check out:
- [README.md](README.md) - Usage examples
- [DOCUMENTATION.md](DOCUMENTATION.md) - Developer documentation
- [ROADMAP.md](ROADMAP.md) - Future features

Happy backing up! 🔄
