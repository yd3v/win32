#include <Windows.h>
#include <stdio.h>
#include "Util.h"

int main() {
    char Buffer[260];
    CLEAN(Buffer);
    GetTempPath(sizeof Buffer, Buffer);
    puts(Buffer);
    return 0;
}
