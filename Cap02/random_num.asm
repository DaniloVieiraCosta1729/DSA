section .note.GNU-stack noalloc nowrite noexec

section .data
	time: times 16 db 0
	roof equ 1000

section .text
	global random
random:
	mov rax, 96
	mov rdi, time
	mov rsi, 0
	syscall

	mov rax, qword [time + 8]
	mov rbx, roof
	xor rdx, rdx
	div rbx
	mov rax, rdx
	ret
