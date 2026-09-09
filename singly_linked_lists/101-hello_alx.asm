global main
	extern printf

	section .text
main:
	push rbp
	mov rbp, rsp

	mov rdi, msg
	mov rax, 0
	call printf

	mov rax, 0
	pop rbp
	ret

	section .data
msg:	db "Hello, ALX", 10, 0
