#include <Windows.h>
#include <stdio.h>
int main() {
    char Buffer[260];
    GetCurrentDirectory(sizeof Buffer, Buffer);
    puts(Buffer);
    return 0;
}