	.file	"codigo.c"
	.text
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
	.globl	c
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.zero	4
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$6, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, a(%rip)
	movl	a(%rip), %eax
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
