#include <Windows.h>
#include <stdio.h>
int main() {
    while(1) {
        int Enable;
        printf("> ");
        if(getch() == 'E') {
                   Enable = 1;  
        } else {
                   Enable = 0;
        }
        puts("Wait...");
        Sleep(3000);
        EnableWindow(GetForegroundWindow(), Enable);
        puts("Ok");
}
}
