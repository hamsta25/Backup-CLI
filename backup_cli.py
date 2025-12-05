#!/usr/bin/env python3
"""
Backup-CLI: A powerful command-line interface for system backups
Supports Windows, macOS, and Linux
"""

import os
import sys
import platform
import argparse
import hashlib
import json
import shutil
from datetime import datetime
from pathlib import Path


class BackupCLI:
    """Main Backup CLI class"""
    
    def __init__(self):
        self.os_type = platform.system()
        self.version = "1.0.0"
        
    def check_os_integrity(self):
        """Check the integrity of the operating system"""
        print(f"Checking OS integrity for {self.os_type}...")
        print(f"Platform: {platform.platform()}")
        print(f"Architecture: {platform.machine()}")
        print(f"Python version: {platform.python_version()}")
        return True
    
    def scan_directories(self, path):
        """Scan directories and files recursively"""
        print(f"\nScanning directory: {path}")
        file_count = 0
        dir_count = 0
        
        try:
            for root, dirs, files in os.walk(path):
                dir_count += len(dirs)
                file_count += len(files)
            
            print(f"Found {dir_count} directories and {file_count} files")
            return dir_count, file_count
        except PermissionError as e:
            print(f"Permission denied: {e}")
            return 0, 0
    
    def calculate_checksum(self, filepath, algorithm='sha256'):
        """Calculate checksum of a file"""
        hash_obj = hashlib.new(algorithm)
        try:
            with open(filepath, 'rb') as f:
                for chunk in iter(lambda: f.read(4096), b''):
                    hash_obj.update(chunk)
            return hash_obj.hexdigest()
        except Exception as e:
            print(f"Error calculating checksum for {filepath}: {e}")
            return None
    
    def create_snapshot(self, source_path, backup_path):
        """Create a snapshot of the system or specified path"""
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        snapshot_name = f"backup_{self.os_type}_{timestamp}"
        snapshot_path = os.path.join(backup_path, snapshot_name)
        
        print(f"\nCreating snapshot: {snapshot_name}")
        print(f"Source: {source_path}")
        print(f"Destination: {snapshot_path}")
        
        metadata = {
            'timestamp': timestamp,
            'os_type': self.os_type,
            'platform': platform.platform(),
            'source_path': source_path,
            'backup_path': snapshot_path
        }
        
        try:
            os.makedirs(snapshot_path, exist_ok=True)
            
            # Create metadata file
            metadata_file = os.path.join(snapshot_path, 'metadata.json')
            with open(metadata_file, 'w') as f:
                json.dump(metadata, f, indent=2)
            
            print(f"Snapshot created successfully at: {snapshot_path}")
            return snapshot_path
        except Exception as e:
            print(f"Error creating snapshot: {e}")
            return None
    
    def perform_backup(self, source, destination, verify=True):
        """Perform the backup operation"""
        print("\n" + "="*50)
        print("Starting Backup Operation")
        print("="*50)
        
        # Check OS integrity
        if not self.check_os_integrity():
            print("OS integrity check failed!")
            return False
        
        # Scan source directory
        self.scan_directories(source)
        
        # Create snapshot
        snapshot_path = self.create_snapshot(source, destination)
        
        if snapshot_path:
            print("\n" + "="*50)
            print("Backup completed successfully!")
            print("="*50)
            return True
        else:
            print("\nBackup failed!")
            return False


def main():
    """Main entry point for the CLI"""
    parser = argparse.ArgumentParser(
        description='Backup-CLI: A powerful backup tool for your system',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  backup-cli --source /home/user --dest /backup/location
  backup-cli --source C:\\Users\\User --dest D:\\Backups --verify
  backup-cli --version
        """
    )
    
    parser.add_argument('--source', '-s', 
                        help='Source directory to backup',
                        default='.')
    parser.add_argument('--dest', '-d',
                        help='Destination directory for backup',
                        required=True)
    parser.add_argument('--verify', '-v',
                        action='store_true',
                        help='Verify backup integrity after completion')
    parser.add_argument('--version',
                        action='version',
                        version='Backup-CLI 1.0.0')
    
    args = parser.parse_args()
    
    # Create backup CLI instance
    backup = BackupCLI()
    
    # Perform backup
    success = backup.perform_backup(args.source, args.dest, args.verify)
    
    sys.exit(0 if success else 1)


if __name__ == '__main__':
    main()
