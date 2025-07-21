section .data
	list db 1, 2, 3, 4, 5

section .text
global _start

_start:
	mov eax, 0
	mov cl,  0	; 8-bit portion of the register ecx (ecx -> cx -> cl)

loop:
	mov bl,  [list + eax]
	add cl,  bl
	add eax, 1
	cmp eax, 5
	je  end
	jmp loop

end:
	mov eax, 1
	mov ebx, 1
	int 0x80
