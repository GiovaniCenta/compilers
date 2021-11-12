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


	.comm	vetor[2][5][0],20,16
## TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _y(%rip)
## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_MOVE_VECTOR
	movl	$44, 8+vetor[2](%rip)
	movl	$0, %eax
## TAC_MOVE_VECTOR
	movl	$77, 20+vetor[2][5](%rip)
	movl	$0, %eax
## TAC_MOVE_VECTOR
	movl	$99, 0+vetor[2][5][0](%rip)
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_vetor[2][5][0](%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_vetor[2][5][0](%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movl	_vetor[2][5][0](%rip), %edx
	movl	_7(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp0(%rip)
	movl	_vetor[2][5][0](%rip), %edx
	movl	_2(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp1(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp1(%rip), %eax
	movl	%eax, _y(%rip)
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_main_Return: .long	0
_0: .long	0
_2: .long	2
_5: .long	5
_7: .long	7
_77: .long	77
_y: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_99: .long	99
_vetor[2][5][0]: .zero	400
_44: .long	44
_n: .string	"\n"
.section .rodata
