#include <windows.h>
#include <stdio.h>
int main(int argc, char* argv[]) {
    if(argc < 3) {
        puts("Usage: Message <title> <content>");
        return 1;
    }
    return MessageBoxA(NULL, argv[2], argv[1], MB_OK | MB_ICONASTERISK);
}
