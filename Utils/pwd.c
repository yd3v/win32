#include <windows.h>
#include <stdio.h>
int main() {
    char Buffer[MAX_PATH];  // 260
    GetCurrentDirectory(sizeof Buffer, Buffer);
    puts(Buffer);
    return 0;
}
