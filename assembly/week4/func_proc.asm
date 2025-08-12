section .data

section .text
global main

addTwo:
	add eax, ebx
	ret

main:
	mov eax, 7
	mov ebx, 4
	call addTwo
	mov ebx, eax
	mov eax, 1
	int 0x80

