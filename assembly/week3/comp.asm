section .text
global _start

_start:
	mov eax, 1
	mov ebx, 2
	cmp eax, ebx
	jl  lesser
			; jg  greater
			; je  equal
			; jle lesser or equal
			; jge greater or equal
			; jne not equal
			; jz  zero
			; jnz not zero
	jmp end

lesser:
	mov ecx, 1

end:
	int 0x80
