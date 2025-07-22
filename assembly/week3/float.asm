section .data
	x dd 3.14
	y dd 2.1

section .text
global _start

_start:
	movss xmm0, [x]		; ss -> single precision
	movss xmm1, [y]
	addss xmm0, xmm1

	movss xmm0, [x]
        movss xmm1, [y]
	ucomiss xmm0, xmm1	; floating point comparison
	ja  greater		; 	     (above)
				; jb  lesser (below)
				; jae above or equal
				; jbe below or equal
	jmp end

greater:
	mov ecx, 1

end:
	mov eax, 1
	mov ebx, 1
	int 0x80
