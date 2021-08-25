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
    Filename:   db "Files\File1.txt", 0x0

section .bss
     Buffer:    resb 1024
     Handle:    resb 1

section .text
    _start:
        push    0                   ; NULL
        push    128                 ; FILE_ATTRIBUTE_NORMAL
        push    4                   ; OPEN_ALWAYS
        push    0                   ; NULL
        push    2                   ; FILE_SHARE_WRITE
        push    1073741824          ; GENERIC_WRITE
        push    Filename            ; Guess
        call    CreateFileA         ; Call CreateFileA 
        mov     [Handle],   eax     ; Stores the value returned by CreateFileA in Handle


    _exit:
        call ExitProcess