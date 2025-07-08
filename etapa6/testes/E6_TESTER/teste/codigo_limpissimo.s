	.file	"codigo.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$5, -4(%rbp)
	movl	$0, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
