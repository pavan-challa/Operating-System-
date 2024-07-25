#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void listFiles(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    // Open directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Read directory entries
    printf("Listing of directory: %s\n", path);
    while ((entry = readdir(dir)) != NULL) {
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get file/directory information
        if (stat(fullpath, &info) != -1) {
            printf("%-20s", entry->d_name);
            if (S_ISDIR(info.st_mode)) {
                printf("<DIR>\n");
            } else {
                printf("%ld bytes\n", (long) info.st_size);
            }
        } else {
            perror("stat");
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *path;

    if (argc < 2) {
        // No directory specified, list current directory
        path = ".";
    } else {
        // Directory specified as argument
        path = argv[1];
    }

    listFiles(path);

    return 0;
}

