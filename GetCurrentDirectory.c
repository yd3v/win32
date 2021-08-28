#include <Windows.h>
#include <stdio.h>
#include "Util.h"
int main() {
    char Buffer[MAX_PATH];
    CLEAN(Buffer);
    GetCurrentDirectory(sizeof Buffer, Buffer);
    puts(Buffer);
    return 0;
}
