#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int fd; // File descriptor

    // Open a file for writing
    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd == -1)
        error("open");

    // Write data to the file
    char *data = "Hello, Unix I/O System Calls!\n";
    ssize_t num_written = write(fd, data, strlen(data));
    if (num_written == -1)
        error("write");

    printf("Data written to file successfully.\n");

    // Close the file
    if (close(fd) == -1)
        error("close");

    // Open the file for reading
    fd = open("output.txt", O_RDONLY);
    if (fd == -1)
        error("open");

    // Read data from the file
    char buffer[BUFFER_SIZE];
    ssize_t num_read = read(fd, buffer, BUFFER_SIZE);
    if (num_read == -1)
        error("read");

    printf("Read %zd bytes from file: \n%s\n", num_read, buffer);

    // Close the file
    if (close(fd) == -1)
        error("close");

    return 0;
}

