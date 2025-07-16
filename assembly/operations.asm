section .data
	num1 db 5
	num2 db 7

section .text
global _start

_start:
	mov al, [num1]
	mov bl, [num2]
	add al, bl
	int 0x80
