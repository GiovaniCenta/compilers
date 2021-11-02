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
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_PRINT
	movl	_ameixa(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_str0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	 call _pastel 
## TAC_MOVE
	movl	_mYWeeirT_emp4(%rip), %eax
	movl	%eax, _ameixa(%rip)
## TAC_ENDFUN
	popq	%rbp
	ret
## TAC_BEGINFUN
.globl	_pastel
_pastel:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	_ameixa(%rip), %edx
	movl	_10(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp5(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp5(%rip), %eax
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

## DATA SECTION
.data
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_mYWeeirT_emp3: .long	0
_mYWeeirT_emp4: .long	0
_10: .long	10
_mYWeeirT_emp5: .long	0
_ameixa: .long	0
_str0: .string	"\n"
.section .rodata
