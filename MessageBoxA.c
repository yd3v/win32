#include <Windows.h>
#include <string.h>
#include <stdio.h>
int main() {
    char Message[25];
    int MessageResult;
    
    do {
        MessageResult = MessageBoxA(
            NULL,                                       // Window handle (NULL in this case)
            "H3333333333333y!",                         // Message content
            "Hello Winapi",                             // Message caption
            MB_ABORTRETRYIGNORE | MB_ICONINFORMATION    // Box buttons / icon
            );
    } while(
        MessageResult == 4                              // Code for `retry` choose
    );
    snprintf(Message, sizeof Message, "Bye bye. Exit code -> %d", MessageResult);
    MessageBox(NULL, Message, "Quitting", MB_OK | MB_ICONINFORMATION);
    return MessageResult;
}