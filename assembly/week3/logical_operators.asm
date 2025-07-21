section .text
global _start

_start:
	mov eax, 0b1010
	mov ebx, 0b0110
	and eax, ebx
	
	mov eax, 0b1010
	mov ebx, 0b0110
	or eax, ebx
	
	mov eax, 0b1010
	mov ebx, 0b0110
	xor eax, ebx

	int 0x80
