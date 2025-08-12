extern printf
extern exit

; printf(fmt, val)

segment .data
	msg  dd "Arda Turkmenoglu", 0
	msg2 dd "Ayda Aytimur", 0
	fmt  db "Output: %s loves %s.", 10, 0

segment .text
global main

main:
	push msg2
	push msg
	push fmt
	call printf
	push 1
	call exit

