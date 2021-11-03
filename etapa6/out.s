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
	 movl	%esi,_p2(%rip)
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
_mYWeeirT_emp3: .long	0
_10: .long	10
_890: .long	890
_p1: .long	0
_100: .long	100
_ameixa: .long	0
_p2: .long	0
.section .rodata
