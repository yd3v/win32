extern MessageBoxA
extern ExitProcess

section .rodata
    Caption:    db "Hello Winapi",      0x0
    Text:       db "H3333333333333y!",  0x0
    global _start

section .text
    _start:
        push    2              ; Buttons and icons (MB_ABORTRETRYIGNORE)
        push    Caption        ; Guess
        push    Text           ; Guess too
        push    0              ; Window Handle
        call    MessageBoxA    ; MessageBoxA(0, Text, Caption, 2);
                               ;
        push    eax            ; Return code to ExitProcess (MessageBoxA return)
        cmp     eax,    4      ;                                    
        je      _start         ;                                    |
                               ;                                    |   
    _exit:                     ;                                    V
        call    ExitProcess    ;                                exit(eax)
