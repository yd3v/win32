bits 32
extern ExitProcess
extern GetCurrentDirectory

section .rodata
    global      _start

section .bss
    Buffer:     resb 260

section .text
    _start:
        push    Buffer
        push    260
        call    GetCurrentDirectory

    _exit:
        push    0
        call    ExitProcess
        