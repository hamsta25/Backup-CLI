cmake_minimum_required(VERSION 3.10)
project(BackupCLI VERSION 1.0.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add executable
add_executable(backup-cli backup_cli.c)

# Set compiler flags
if(MSVC)
    target_compile_options(backup-cli PRIVATE /W4)
else()
    target_compile_options(backup-cli PRIVATE -Wall -Wextra -O2)
endif()

# Installation rules
install(TARGETS backup-cli
        RUNTIME DESTINATION bin)

# Platform-specific settings
if(WIN32)
    # Windows specific settings
    set_target_properties(backup-cli PROPERTIES
        OUTPUT_NAME "backup-cli"
        SUFFIX ".exe")
elseif(APPLE)
    # macOS specific settings
    set_target_properties(backup-cli PROPERTIES
        OUTPUT_NAME "backup-cli")
elseif(UNIX)
    # Linux specific settings
    set_target_properties(backup-cli PROPERTIES
        OUTPUT_NAME "backup-cli")
endif()

# Package configuration
set(CPACK_PACKAGE_NAME "backup-cli")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 0)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A powerful command-line interface for system backups")
set(CPACK_PACKAGE_VENDOR "Backup-CLI Team")

# Platform-specific package generators
if(WIN32)
    set(CPACK_GENERATOR "ZIP;NSIS")
elseif(APPLE)
    set(CPACK_GENERATOR "ZIP;DragNDrop")
else()
    set(CPACK_GENERATOR "TGZ;DEB;RPM")
endif()

include(CPack)
