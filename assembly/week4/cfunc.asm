extern test
extern exit

section .data

section .text
global main

main:
	push 5
	push 7
	call test
	push eax
	call exit
	
