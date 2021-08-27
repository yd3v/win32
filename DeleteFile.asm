bits 32
extern ExitProcess
extern DeleteFile

section .rodata
    global      _start
    Filename:   db "DeleteMe.txt"

section .text
    _start:
        push Filename
        call DeleteFile

    _exit:
        push    0
        call ExitProcess