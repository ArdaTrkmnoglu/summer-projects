section .data

section .text
global _start

start:
    mov eax, 1      ; syscall exit
    mov ebx, 31     ; exit code
    int 0x80        ; system interrupt: exit
