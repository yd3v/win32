#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#include "Util.h"

int main() {
    setlocale(LC_ALL, "");
    HWND Handle;
    Handle=CreateWindow(L"BUTTON", "Window1", 1, 10, 10, 10, 10, 0, 0, 0, 0);
    if(Handle == NULL){
        PERROR(GetLastError());
        MessageBoxA(NULL, "Unable to create window", "Error", MB_ICONERROR | MB_OK);
        return 1;
    }
    printf("Handle -> %d\n", Handle);
}
