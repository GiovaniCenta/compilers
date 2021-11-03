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
	 movl	%edi,_p2(%rip)
	 movl	%edx,_p3(%rip)
	 movl	%ecx,_p4(%rip)
	 movl	%eax,_p5(%rip)
## TAC_PRINT
	movl	_p3(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_str0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movl	_p1(%rip), %edx
	movl	_p2(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp0(%rip)
	movl	_mYWeeirT_emp0(%rip), %edx
	movl	_p3(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp1(%rip)
	movl	_mYWeeirT_emp1(%rip), %edx
	movl	_p4(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp2(%rip)
	movl	_mYWeeirT_emp2(%rip), %edx
	movl	_p5(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp3(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp3(%rip), %eax
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

	 movl	$100,%esi
	 movl	$200,%edi
	 movl	$300,%edx
	 movl	$400,%ecx
	 movl	$500,%eax
	 call _pastel 
## TAC_MOVE
	movl	_pastel(%rip), %eax
	movl	%eax, _ameixa(%rip)
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_p5: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_300: .long	300
_mYWeeirT_emp2: .long	0
_mYWeeirT_emp3: .long	0
_mYWeeirT_emp4: .long	0
_10: .long	10
_mYWeeirT_emp5: .long	0
_400: .long	400
_p1: .long	0
_100: .long	100
_ameixa: .long	0
_p2: .long	0
_p3: .long	0
_str0: .string	"\n"
_500: .long	500
_p4: .long	0
_200: .long	200
.section .rodata
