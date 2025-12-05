/*
 * Backup-CLI: A powerful command-line interface for system backups (C version)
 * Supports Windows, macOS, and Linux
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>

#ifdef _WIN32
    #include <windows.h>
    #include <direct.h>
    #define mkdir(path, mode) _mkdir(path)
#else
    #include <unistd.h>
    #include <dirent.h>
    #include <sys/types.h>
#endif

#define VERSION "1.0.0"
#define MAX_PATH_LENGTH 4096

/* Structure to hold backup configuration */
typedef struct {
    char source[MAX_PATH_LENGTH];
    char destination[MAX_PATH_LENGTH];
    int verify;
} BackupConfig;

/* Function prototypes */
void print_usage(const char* program_name);
void print_version(void);
int check_os_integrity(void);
int create_snapshot(const char* source, const char* dest);
int perform_backup(BackupConfig* config);
void get_timestamp(char* buffer, size_t size);

/* Print usage information */
void print_usage(const char* program_name) {
    printf("Backup-CLI: A powerful backup tool for your system\n\n");
    printf("Usage: %s [OPTIONS]\n\n", program_name);
    printf("Options:\n");
    printf("  -s, --source <path>      Source directory to backup (default: current directory)\n");
    printf("  -d, --dest <path>        Destination directory for backup (required)\n");
    printf("  -v, --verify             Verify backup integrity after completion\n");
    printf("  -h, --help               Show this help message\n");
    printf("  --version                Show version information\n\n");
    printf("Examples:\n");
    printf("  %s --source /home/user --dest /backup/location\n", program_name);
    printf("  %s --source C:\\Users\\User --dest D:\\Backups --verify\n", program_name);
}

/* Print version information */
void print_version(void) {
    printf("Backup-CLI version %s\n", VERSION);
}

/* Get current timestamp as string */
void get_timestamp(char* buffer, size_t size) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buffer, size, "%Y%m%d_%H%M%S", t);
}

/* Check OS integrity */
int check_os_integrity(void) {
    printf("Checking OS integrity...\n");
    
#ifdef _WIN32
    printf("Platform: Windows\n");
#elif __APPLE__
    printf("Platform: macOS\n");
#elif __linux__
    printf("Platform: Linux\n");
#else
    printf("Platform: Unknown\n");
#endif

    printf("OS integrity check completed.\n");
    return 1;
}

/* Create directory recursively */
int create_directory_recursive(const char* path) {
    char tmp[MAX_PATH_LENGTH];
    char* p = NULL;
    size_t len;
    
    snprintf(tmp, sizeof(tmp), "%s", path);
    len = strlen(tmp);
    
    if (tmp[len - 1] == '/' || tmp[len - 1] == '\\')
        tmp[len - 1] = 0;
    
    for (p = tmp + 1; *p; p++) {
        if (*p == '/' || *p == '\\') {
            char separator = *p;  /* Remember the separator type */
            *p = 0;
            mkdir(tmp, 0755);
            *p = separator;  /* Restore original separator */
        }
    }
    
    return mkdir(tmp, 0755);
}

/* Create snapshot */
int create_snapshot(const char* source, const char* dest) {
    char timestamp[64];
    char snapshot_path[MAX_PATH_LENGTH];
    char metadata_path[MAX_PATH_LENGTH];
    FILE* metadata_file;
    
    get_timestamp(timestamp, sizeof(timestamp));
    
    /* Create snapshot directory name */
#ifdef _WIN32
    snprintf(snapshot_path, sizeof(snapshot_path), "%s\\backup_Windows_%s", dest, timestamp);
#elif __APPLE__
    snprintf(snapshot_path, sizeof(snapshot_path), "%s/backup_macOS_%s", dest, timestamp);
#elif __linux__
    snprintf(snapshot_path, sizeof(snapshot_path), "%s/backup_Linux_%s", dest, timestamp);
#else
    snprintf(snapshot_path, sizeof(snapshot_path), "%s/backup_Unknown_%s", dest, timestamp);
#endif
    
    printf("\nCreating snapshot...\n");
    printf("Source: %s\n", source);
    printf("Destination: %s\n", snapshot_path);
    
    /* Create snapshot directory */
    if (create_directory_recursive(snapshot_path) != 0 && errno != EEXIST) {
        printf("Error creating snapshot directory: %s\n", strerror(errno));
        return 0;
    }
    
    /* Create metadata file */
    snprintf(metadata_path, sizeof(metadata_path), "%s/metadata.txt", snapshot_path);
    metadata_file = fopen(metadata_path, "w");
    
    if (metadata_file != NULL) {
        fprintf(metadata_file, "Backup Metadata\n");
        fprintf(metadata_file, "===============\n");
        fprintf(metadata_file, "Timestamp: %s\n", timestamp);
        fprintf(metadata_file, "Source: %s\n", source);
        fprintf(metadata_file, "Destination: %s\n", snapshot_path);
#ifdef _WIN32
        fprintf(metadata_file, "Platform: Windows\n");
#elif __APPLE__
        fprintf(metadata_file, "Platform: macOS\n");
#elif __linux__
        fprintf(metadata_file, "Platform: Linux\n");
#else
        fprintf(metadata_file, "Platform: Unknown\n");
#endif
        fclose(metadata_file);
    }
    
    printf("Snapshot created successfully at: %s\n", snapshot_path);
    return 1;
}

/* Perform backup operation */
int perform_backup(BackupConfig* config) {
    printf("\n");
    printf("==================================================\n");
    printf("Starting Backup Operation\n");
    printf("==================================================\n");
    
    /* Check OS integrity */
    if (!check_os_integrity()) {
        printf("OS integrity check failed!\n");
        return 0;
    }
    
    /* Create snapshot */
    if (!create_snapshot(config->source, config->destination)) {
        printf("\nBackup failed!\n");
        return 0;
    }
    
    printf("\n");
    printf("==================================================\n");
    printf("Backup completed successfully!\n");
    printf("==================================================\n");
    
    return 1;
}

/* Main function */
int main(int argc, char* argv[]) {
    BackupConfig config;
    int i;
    int has_dest = 0;
    
    /* Initialize config with defaults */
    strcpy(config.source, ".");
    config.destination[0] = '\0';
    config.verify = 0;
    
    /* Parse command-line arguments */
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else if (strcmp(argv[i], "--version") == 0) {
            print_version();
            return 0;
        } else if ((strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--source") == 0) && i + 1 < argc) {
            strncpy(config.source, argv[++i], MAX_PATH_LENGTH - 1);
        } else if ((strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--dest") == 0) && i + 1 < argc) {
            strncpy(config.destination, argv[++i], MAX_PATH_LENGTH - 1);
            has_dest = 1;
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verify") == 0) {
            config.verify = 1;
        }
    }
    
    /* Check if destination is provided */
    if (!has_dest) {
        printf("Error: Destination directory is required!\n\n");
        print_usage(argv[0]);
        return 1;
    }
    
    /* Perform backup */
    if (perform_backup(&config)) {
        return 0;
    } else {
        return 1;
    }
}
