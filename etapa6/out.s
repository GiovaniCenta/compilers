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
	movl	_10(%rip), %eax
	movl	%eax, _xuxu(%rip)
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
	movl	_5(%rip), %edx
	movl	_p2(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp0(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp0(%rip), %eax
	movl	%eax, _p1(%rip)
	##TAC_RET
	movl	_p1(%rip), %eax
## TAC_ENDFUN
	popq	%rbp
	ret
## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_PRINT_STRING
	leaq	_oiestringcomespaço(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_oie2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_xuxu(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_depois(%rip), %rdi
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
_p5: .long	0
_main_Return: .long	0
_0: .long	0
_5: .long	5
_i: .long	0
_mYWeeirT_emp0: .long	0
_pastel_Return: .long	0
_10: .long	10
_p1: .long	0
_xuxu: .long	0
_ameixa: .long	0
_oie2: .string	"oie2"
_p2: .long	0
_oiestringcomespaço: .string	"oie string com espaço"
_p3: .long	0
_n: .string	"\n"
_depois: .string	"depois"
_p4: .long	0
.section .rodata
