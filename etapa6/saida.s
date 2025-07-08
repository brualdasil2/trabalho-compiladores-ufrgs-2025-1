	
	.text 
	.bss 
	.globl  a
	.align 4 
	.type  a, @object
	.size  a, 4
a: 
	.zero  4
	.globl  c
	.align 4 
	.type  c, @object
	.size  c, 4
c: 
	.zero  4
	.text 
	.globl	main 
	.type	main, @function 
main: 
	pushq %rbp 
	movq	%rsp, %rbp 
	movl  $5, -4(%rbp)
	movl  -4(%rbp), %edx
	movl  %edx, a(%rip)
	movl  a(%rip), %eax
	popq  %rbp
	ret 
