#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "Util.h"

#define SLEEP 100

int main() {
    HWND		Handle;
    RECT		WRect;
    WINDOWINFO	WInfo;

    char WText[1024];

    while(1) {
        Sleep(SLEEP);
        system("cls");
        Handle = GetForegroundWindow();
        if(GetWindowText(Handle, WText, sizeof WText)) {
                printf(":: %s\n\n", WText);
        }

        if(GetWindowInfo(Handle, &WInfo)) {
                printf("Window Borders (x, y) -> %d, %d\n",		WInfo.cxWindowBorders, WInfo.cyWindowBorders);
                printf("Window Position       -> %d - %d\n",	WInfo.rcWindow.top, WInfo.rcWindow.left);
                printf("Window Size           -> %d x %d",		WInfo.rcWindow.bottom - WInfo.rcWindow.top, WInfo.rcClient.right - WInfo.rcWindow.left);

        }
    }
    return 0;
}
