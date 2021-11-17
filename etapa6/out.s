.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"

## VAR DECLARATION
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _y(%rip)
## TAC_MOVE
	movl	_15(%rip), %eax
	movl	%eax, _k(%rip)
	call	_main
## TAC_ENDFUN
	popq	%rbp
	ret


	.comm	vetor,60,16
	.comm	vetor3,48,16
	.comm	vetor2,20,16
## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

	 movl	$1,%esi
	 movl	$2,%edi
	 movl	$3,%edx
	 movl	$4,%ecx
	 call _function 
	movl	%eax,_function_Return(%rip)
## TAC_MOVE
	movl	_function(%rip), %eax
	movl	%eax, _k(%rip)
## OPERATION EDX EAX
	movl	_10(%rip), %edx
	movl	_5(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp2(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp2(%rip), %eax
	movl	%eax, _k(%rip)
	##TAC_RET
	movl	_5(%rip), %eax
## TAC_ENDFUN
	popq	%rbp
	ret
## TAC_BEGINFUN
.globl	_function
_function:
	pushq	%rbp
	movq	%rsp, %rbp

	 movl	%esi,_p1(%rip)
	 movl	%edi,_p2(%rip)
	 movl	%edx,_p3(%rip)
## OPERATION EDX EAX
	movl	_15(%rip), %edx
	movl	_"string"(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp3(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp3(%rip), %eax
	movl	%eax, _y(%rip)
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_main_Return: .long	0
_0: .long	0
_1: .long	1
_2: .long	2
_3: .long	3
_4: .long	4
_5: .long	5
_k: .long	0
_y: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_vetor3: .zero	400
_mYWeeirT_emp3: .long	0
_10: .long	10
_string: .string	"string"
_12: .long	12
_vetor: .zero	400
_p1: .long	0
_15: .long	15
_p2: .long	0
_vetor2: .zero	400
_p3: .long	0
_function_Return: .long	0
.section .rodata
