@echo off
REM Build script for Backup-CLI (Windows)

echo ================================
echo Backup-CLI Build Script (Windows)
echo ================================
echo.

REM Build Python package
echo Building Python package...
python -m pip install --upgrade pip setuptools wheel build
python -m build
echo Python package built successfully
echo.

REM Build C version
echo Building C version...
echo Using MinGW make...
mingw32-make
if errorlevel 1 (
    echo Trying with MSVC...
    cl /W4 /O2 backup_cli.c /Fe:backup-cli.exe
)
echo C version built successfully
echo.

REM Create distribution directory
echo Creating distribution directory...
if not exist dist\backup-cli-Windows mkdir dist\backup-cli-Windows
echo Distribution directory created
echo.

REM Copy files
echo Copying files to distribution...
copy backup-cli.exe dist\backup-cli-Windows\
copy README.md dist\backup-cli-Windows\
copy LICENSE dist\backup-cli-Windows\
echo Files copied
echo.

REM Create archive
echo Creating archive...
cd dist
powershell Compress-Archive -Path backup-cli-Windows -DestinationPath backup-cli-Windows.zip -Force
cd ..
echo Archive created: dist\backup-cli-Windows.zip
echo.

echo ================================
echo Build completed successfully!
echo ================================
echo.
echo Python package: dist\*.whl
echo C binary: backup-cli.exe
echo Distribution: dist\backup-cli-Windows.zip
