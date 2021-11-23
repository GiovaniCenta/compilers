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
	movl	%eax, _i(%rip)
	call	_main
## TAC_ENDFUN
	popq	%rbp
	ret


## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

## OPERATION EDX EAX
	movl	_i(%rip), %edx
	movl	_12(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp6(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp6(%rip), %eax
	movl	%eax, _i(%rip)
## OPERATION EDX EAX
	movl	_i(%rip), %edx
	movl	_12(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp5(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp5(%rip), %eax
	movl	%eax, _i(%rip)
## OPERATION EDX EAX
	movl	_i(%rip), %edx
	movl	_12(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp4(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp4(%rip), %eax
	movl	%eax, _i(%rip)
## OPERATION EDX EAX
	movl	_i(%rip), %edx
	movl	_12(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp3(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp3(%rip), %eax
	movl	%eax, _i(%rip)
## OPERATION EDX EAX
	movl	_i(%rip), %edx
	movl	_12(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp2(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp2(%rip), %eax
	movl	%eax, _i(%rip)
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_main_Return: .long	0
_0: .long	0
_i: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_mYWeeirT_emp3: .long	0
_mYWeeirT_emp4: .long	0
_mYWeeirT_emp5: .long	0
_12: .long	12
_mYWeeirT_emp6: .long	0
_50: .long	50
.section .rodata
