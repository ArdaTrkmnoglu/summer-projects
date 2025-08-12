section .data

section .text
global main

addTwo:
	push ebp
	mov ebp, esp
	mov eax, [ebp+8]
	mov ebx, [ebp+12]
	add eax, ebx
	pop ebp
	ret

main:
	push 7
	push 4
	call addTwo
	mov ebx, eax
	mov eax, 1
	int 0x80

