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


	.comm	vetor,28,16
## TAC_MOVE
	movl	_7(%rip), %eax
	movl	%eax, _ameixa(%rip)
## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_MOVE_VECTOR
	movl	$55, 20+vetor(%rip)
	movl	$0, %eax
## TAC_MOVE_VECTOR
	movl	$77, 24+vetor(%rip)
	movl	$0, %eax
	movl	_55(%rip), %edx
	movl	_77(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp2(%rip)
	movl	_mYWeeirT_emp2(%rip), %edx
	movl	_90(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp3(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp3(%rip), %eax
	movl	%eax, _ameixa(%rip)
## TAC_PRINT
	movl	_77(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_55: .long	55
_77: .long	77
_7: .long	7
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_mYWeeirT_emp3: .long	0
_vetor: .zero	400
_ameixa: .long	0
_90: .long	90
.section .rodata
