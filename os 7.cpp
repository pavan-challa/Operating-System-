#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hMapFile;
    LPCTSTR pBuf;

    
    hMapFile = CreateFileMapping(
                   INVALID_HANDLE_VALUE,    
                   NULL,                    
                   PAGE_READWRITE,          
                   0,                      
                   1024,                    
                   TEXT("Global\\MySharedMemory")); 
    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

   
    pBuf = (LPTSTR)MapViewOfFile(hMapFile,   
                                 FILE_MAP_ALL_ACCESS, 
                                 0,
                                 0,
                                 1024);

    if (pBuf == NULL) {
        printf("Could not map view of file (%d).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    
    printf("Enter some data to write to shared memory\n");
    char buff[100];
    fgets(buff, sizeof(buff), stdin);

    
    CopyMemory((PVOID)pBuf, buff, (strlen(buff) + 1) * sizeof(char));
    printf("You wrote: %s\n", pBuf);

   
    UnmapViewOfFile(pBuf);

    
    CloseHandle(hMapFile);

    return 0;
}

