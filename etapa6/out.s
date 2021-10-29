.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"

## VAR DECLARATION
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	_'a'(%rip), %eax
	movl	%eax, _z(%rip)
	movl	_10(%rip), %eax
	movl	%eax, _x(%rip)
	movl	_35(%rip), %eax
	movl	%eax, _y(%rip)
	movl	_0(%rip), %eax
	movl	%eax, _k(%rip)
	call	_main
## TAC_ENDFUN
	popq	%rbp
	ret


## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	_x(%rip), %edx
	movl	_y(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp1(%rip)
	movl	_mYWeeirT_emp1(%rip), %eax
	movl	%eax, _k(%rip)
## TAC_PRINT
	movl	_x(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_y(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_k(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_0: .long	0
_k: .long	0
_x: .long	0
_y: .long	0
_z: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_10: .long	10
_35: .long	35
_'a': 	.byte 'a'
.section .rodata
