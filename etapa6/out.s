.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"

## VAR DECLARATION
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_MOVE
	movl	_10(%rip), %eax
	movl	%eax, _ameixa(%rip)
	call	_main
## TAC_ENDFUN
	popq	%rbp
	ret


## TAC_BEGINFUN
.globl	_pastel
_pastel:
	pushq	%rbp
	movq	%rsp, %rbp

	 movl	%esi,_p1(%rip)
	movl	_ameixa(%rip), %edx
	movl	_p1(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp0(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp0(%rip), %eax
	movl	%eax, _ameixa(%rip)
## TAC_PRINT
	movl	_ameixa(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_ENDFUN
	popq	%rbp
	ret
## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

	 movl	$890,%esi
	 call _pastel 
## TAC_MOVE
	movl	_pastel(%rip), %eax
	movl	%eax, _ameixa(%rip)
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_10: .long	10
_890: .long	890
_p1: .long	0
_ameixa: .long	0
.section .rodata
