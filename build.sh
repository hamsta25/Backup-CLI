#!/bin/bash
# Build script for Backup-CLI

set -e

echo "================================"
echo "Backup-CLI Build Script"
echo "================================"
echo ""

# Detect platform
OS="$(uname -s)"
case "${OS}" in
    Linux*)     PLATFORM=Linux;;
    Darwin*)    PLATFORM=macOS;;
    CYGWIN*)    PLATFORM=Windows;;
    MINGW*)     PLATFORM=Windows;;
    *)          PLATFORM="UNKNOWN:${OS}"
esac

echo "Platform detected: ${PLATFORM}"
echo ""

# Build Python package
echo "Building Python package..."
python3 -m pip install --upgrade pip setuptools wheel build
python3 -m build
echo "✓ Python package built successfully"
echo ""

# Build C version
echo "Building C version..."
if [ "$PLATFORM" = "Windows" ]; then
    echo "Using MinGW make..."
    mingw32-make
else
    make
fi
echo "✓ C version built successfully"
echo ""

# Create distribution directory
echo "Creating distribution directory..."
mkdir -p dist/backup-cli-${PLATFORM}
echo "✓ Distribution directory created"
echo ""

# Copy files
echo "Copying files to distribution..."
if [ "$PLATFORM" = "Windows" ]; then
    cp backup-cli.exe dist/backup-cli-${PLATFORM}/
else
    cp backup-cli dist/backup-cli-${PLATFORM}/
fi
cp README.md dist/backup-cli-${PLATFORM}/
cp LICENSE dist/backup-cli-${PLATFORM}/
echo "✓ Files copied"
echo ""

# Create archive
echo "Creating archive..."
cd dist
if [ "$PLATFORM" = "Windows" ]; then
    zip -r backup-cli-${PLATFORM}.zip backup-cli-${PLATFORM}/
    echo "✓ Archive created: dist/backup-cli-${PLATFORM}.zip"
else
    tar czf backup-cli-${PLATFORM}.tar.gz backup-cli-${PLATFORM}/
    echo "✓ Archive created: dist/backup-cli-${PLATFORM}.tar.gz"
fi
cd ..

echo ""
echo "================================"
echo "Build completed successfully!"
echo "================================"
echo ""
echo "Python package: dist/*.whl"
echo "C binary: backup-cli"
if [ "$PLATFORM" = "Windows" ]; then
    echo "Distribution: dist/backup-cli-${PLATFORM}.zip"
else
    echo "Distribution: dist/backup-cli-${PLATFORM}.tar.gz"
fi
