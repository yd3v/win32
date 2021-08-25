; Pls be patient, i'll comment it
; :D

bits 32
extern CreateFileA
extern ReadFile
extern WriteFile
extern ExitProcess

section .rodata
    global _start
    ToWrite:    db "New Line",  0xa
    Filename:   db "File1.txt"

section .bss
     Buffer:    resb 1024
     Handle:    resb 8

section .text
    _start:
        push    0
        push    4
        push    0
        push    2
        push    1073741824
        push    Filename
        call    CreateFileA
        mov     [Handle],   eax

    _exit:
        call ExitProcess