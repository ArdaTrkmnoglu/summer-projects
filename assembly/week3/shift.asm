section .text
global _start

_start:
	mov eax, 2
	shr eax, 1	; 0010 -> 0001
	shl eax, 3	; 0001 -> 1000

	mov ebx, 12
	shr ebx, 2	; 12 / (2^2) = 3
	shl ebx, 4	; 3 * (2^4) = 48

	int 0x80

