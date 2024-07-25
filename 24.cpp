#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void createFile(const char *filename) {
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    printf("File '%s' created successfully.\n", filename);
    close(fd);
}

void writeFile(const char *filename, const char *content) {
    int fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    if (write(fd, content, strlen(content)) == -1) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }
    printf("Data written to file '%s' successfully.\n", filename);
    close(fd);
}

void readFile(const char *filename) {
    char buffer[BUFFER_SIZE];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    ssize_t bytes_read;
    printf("Contents of file '%s':\n", filename);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    if (bytes_read == -1) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    close(fd);
}

int main() {
    const char *filename = "example.txt";
    const char *content = "Hello, Unix System Calls!\nThis is a demonstration of file management in C.\n";

    createFile(filename);
    writeFile(filename, content);
    readFile(filename);

    return 0;
}

