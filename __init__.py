"""
Backup-CLI Package
A powerful command-line interface for system backups
"""

__version__ = "1.0.0"
__author__ = "Backup-CLI Team"
__license__ = "MIT"

from .backup_cli import BackupCLI, main

__all__ = ['BackupCLI', 'main']
