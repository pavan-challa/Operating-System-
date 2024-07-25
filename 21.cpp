#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTITIONS 50

struct MemoryPartition {
    int size;
    int allocated;
};

struct MemoryPartition memory[MAX_PARTITIONS];

void initializeMemory() {
    int i;
    for (i = 0; i < MAX_PARTITIONS; i++) {
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}

void allocateMemory(int processSize) {
    int i, largest_index = -1;

    // Find the largest free partition that can accommodate the process
    for (i = 0; i < MAX_PARTITIONS; i++) {
        if (!memory[i].allocated) {
            if (largest_index == -1 || memory[i].size > memory[largest_index].size) {
                largest_index = i;
            }
        }
    }

    if (largest_index != -1 && memory[largest_index].size >= processSize) {
        memory[largest_index].allocated = 1;
        printf("Memory allocated successfully at partition %d.\n", largest_index + 1);
    } else {
        printf("Memory allocation failed for size %d.\n", processSize);
    }
}

void deallocateMemory(int partitionIndex) {
    if (partitionIndex >= 0 && partitionIndex < MAX_PARTITIONS) {
        if (memory[partitionIndex].allocated) {
            memory[partitionIndex].allocated = 0;
            printf("Memory at partition %d deallocated successfully.\n", partitionIndex + 1);
        } else {
            printf("Partition %d is already free.\n", partitionIndex + 1);
        }
    } else {
        printf("Invalid partition index.\n");
    }
}

void displayMemoryStatus() {
    int i;
    printf("\nPartition\tSize\tAllocated\n");
    for (i = 0; i < MAX_PARTITIONS; i++) {
        printf("%d\t\t%d\t%s\n", i + 1, memory[i].size, memory[i].allocated ? "Yes" : "No");
    }
}

int main() {
    int choice, processSize, partitionIndex;

    initializeMemory();

    while (1) {
        printf("\n\nMemory Management Menu:\n");
        printf("1. Allocate Memory\n");
        printf("2. Deallocate Memory\n");
        printf("3. Display Memory Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the process: ");
                scanf("%d", &processSize);
                allocateMemory(processSize);
                break;
            case 2:
                printf("Enter the partition index to deallocate: ");
                scanf("%d", &partitionIndex);
                deallocateMemory(partitionIndex - 1);
                break;
            case 3:
                displayMemoryStatus();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

