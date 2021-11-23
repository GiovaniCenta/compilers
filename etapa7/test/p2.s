	.file	"t1.c"
	.text
	.globl	x
	.data
	.type	x, @object
	.size	x, 4
x:
	.long	10
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:

	
	pushq	%rbp

	movq	%rsp, %rbp
	
	movl	x(%rip), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	
	ret
	

