// https://docs.microsoft.com/en-us/windows/win32/fileio/creating-and-opening-files
// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea
// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-writefile

#include <Windows.h>
#include <stdio.h>

#define PINT(n) (printf("%d\n", n))
#define CLEAN(s) (memset(s, 0x0, sizeof s))

#define FILE "Files\\File.txt"

int main() {
    char Buffer[1024];
    char ToWrite[] = "New line\n";
    DWORD Written;
    DWORD Read;

    HANDLE Handle = CreateFile(
        FILE,                               // File name
        GENERIC_READ | GENERIC_WRITE,       // Opening mode (Write or read)
        FILE_SHARE_READ | FILE_SHARE_WRITE, // Sharing mode (Read, write, or nothing by other processes)
        NULL,                               // Security attributes 
        OPEN_ALWAYS,                        // Choose the opening mode (What to do if the file exists, or not)
        FILE_ATTRIBUTE_NORMAL,              // Opening attributes
        NULL                                // File flags and attributes
    );
 
    CLEAN(Buffer);

    ReadFile(
        Handle,         // A handle to the open file
        Buffer,         // A pointer to buffer to store the file content
        sizeof Buffer,  // Number of bytes to read
        &Read,          // A pointer to int to store the number of bytes read
        NULL            // Bleh
    );

    WriteFile(
        Handle,             // Same as ReadFile
        ToWrite,            // A pointer to the buffer that will be written
        (sizeof ToWrite)-1, // The number of bytes to write
        &Written,           // A pointer to int to store the number of bytes written
        NULL                // Bleh
    );

    puts(Buffer); 
}