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
## TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _i(%rip)
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
	##TAC_RET
	movl	$7777, %eax
## TAC_ENDFUN
	popq	%rbp
	ret
## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp


.mYLabule_0:
	movl	_i(%rip), %edx
	movl	_10(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, _mYWeeirT_emp4(%rip)

## TAC_IFZ
	movl	_mYWeeirT_emp4(%rip), %eax
	testl	%eax, %eax
	jne		.mYLabule_1
	movl	_i(%rip), %edx
	movl	_1(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp5(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp5(%rip), %eax
	movl	%eax, _i(%rip)
## TAC_PRINT
	movl	_i(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	jmp		.mYLabule_0

.mYLabule_1:
## TAC_PRINT
	movl	_i(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_p5: .long	0
_0: .long	0
_1: .long	1
_i: .long	0
_7777: .long	7777
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_mYWeeirT_emp3: .long	0
_mYWeeirT_emp4: .long	0
_10: .long	10
_mYWeeirT_emp5: .long	0
_p1: .long	0
_ameixa: .long	0
_p2: .long	0
_p3: .long	0
_str0: .string	" \n "
_p4: .long	0
.section .rodata
