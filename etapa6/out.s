.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"

## VAR DECLARATION
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

	call	_main
## TAC_ENDFUN
	popq	%rbp
	ret


	.comm	vetor,40,16
## TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _pastel(%rip)
## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_MOVE_VECTOR
	movl	$77, 28+vetor(%rip)
	movl	$0, %eax
## TAC_PRINT_VECTOR
	movl	28+vetor(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_vetor(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_VECTOR
	movl	28+vetor(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movl	_5(%rip), %edx
	movl	_vetor(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp0(%rip)
	movl	_mYWeeirT_emp0(%rip), %edx
	movl	_7(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp1(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp1(%rip), %eax
	movl	%eax, _pastel(%rip)
## TAC_PRINT
	movl	_pastel(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_main_Return: .long	0
_0: .long	0
_5: .long	5
_7: .long	7
_77: .long	77
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_pastel: .long	0
_10: .long	10
_vetor: .zero	400
_n: .string	"\n"
.section .rodata
