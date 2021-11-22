.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"

## VAR DECLARATION
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_MOVE
	movl	_15(%rip), %eax
	movl	%eax, _y(%rip)
## TAC_MOVE
	movl	_10(%rip), %eax
	movl	%eax, _x(%rip)
## TAC_MOVE
	movl	_2(%rip), %eax
	movl	%eax, _ret(%rip)
## TAC_MOVE
	movl	_10(%rip), %eax
	movl	%eax, _vetor(%rip)
## TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _i(%rip)
## TAC_MOVE
	movl	_'a'(%rip), %eax
	movl	%eax, _a(%rip)
	call	_main
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
	movl	_p1(%rip), %edx
	movl	_p2(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp0(%rip)
## OPERATION EAX EDX
	movl	_mYWeeirT_emp0(%rip), %eax
	movl	_p3(%rip), %edx
	subl	%edx, %eax
	movl	%eax, _mYWeeirT_emp1(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp1(%rip), %eax
	movl	%eax, _x(%rip)
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_valordep1p2p3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_x(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## OPERATION EDX EAX
	movl	_x(%rip), %edx
	movl	_2(%rip), %eax
	imull	%edx, %eax
	movl	%eax, _mYWeeirT_emp2(%rip)
	##TAC_RET
	movl	_mYWeeirT_emp2(%rip), %eax
## TAC_ENDFUN
	popq	%rbp
	ret
## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_MOVE_VECTOR
	movl	$1000, 20+_vetor(%rip)
	movl	$0, %eax
## TAC_MOVE_VECTOR
	movl	$2, 8+_vetor(%rip)
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## OPERATION EDX EAX WITH VECTOR OP1
	movl	20+_vetor(%rip), %edx
	movl	_50(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp3(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp3(%rip), %eax
	movl	%eax, _y(%rip)
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_vetor5mais50(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_y(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	 movl	$100,%esi
	 movl	$20,%edi
	 movl	$30,%edx
	 call _function 
	movl	%eax,_function_Return(%rip)
## TAC_FUNCTION_CALL 
 	movl	%eax,_function_Return(%rip)
 	movl _function_Return(%rip), %eax
 	movl %eax,_mYWeeirT_emp4(%rip)
 ## TAC_MOVE
	movl	_mYWeeirT_emp4(%rip), %eax
	movl	%eax, _y(%rip)
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_oretornodafunction(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_y(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax

.mYLabule_0:
	movl	_i(%rip), %edx
	movl	_10(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, _mYWeeirT_emp6(%rip)

## TAC_IFZ
	movl	_mYWeeirT_emp6(%rip), %eax
	testl	%eax, %eax
	jne		.mYLabule_1
## OPERATION EDX EAX
	movl	_i(%rip), %edx
	movl	_2(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp7(%rip)
## TAC_MOVE
	movl	_mYWeeirT_emp7(%rip), %eax
	movl	%eax, _i(%rip)
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_valordei(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_i(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	jmp		.mYLabule_0

.mYLabule_1:
	movl	_x(%rip), %edx
	movl	_10(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, _mYWeeirT_emp8(%rip)

## TAC_IFZ
	movl	_mYWeeirT_emp8(%rip), %eax
	testl	%eax, %eax
	je		.mYLabule_2
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_entreinoifpq(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_valordei(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_i(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	jmp		.mYLabule_3

.mYLabule_2:
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_entreinoelsepq(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_valordei(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT
	movl	_i(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_PRINT_STRING
	leaq	_n(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax

.mYLabule_3:
	##TAC_RET
	movl	_a(%rip), %eax
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_main_Return: .long	0
_0: .long	0
_2: .long	2
_1000: .long	1000
_a: .long	0
_i: .long	0
_x: .long	0
_y: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_valordep1p2p3: .string	"valor de p1 + p2 - p3 = "
_mYWeeirT_emp3: .long	0
_mYWeeirT_emp4: .long	0
_10: .long	10
_mYWeeirT_emp5: .long	0
_20: .long	20
_30: .long	30
_ret: .long	0
_mYWeeirT_emp6: .long	0
_vetor: .zero	400
_p1: .long	0
_valordei: .string	"valor de i = "
_entreinoelsepq: .string	"entrei no else pq "
_mYWeeirT_emp7: .long	0
_100: .long	100
_50: .long	50
_vetor5mais50: .string	"vetor[5] mais 50 = "
_entreinoifpq: .string	"entrei no if pq "
_oretornodafunction: .string	"o retorno da function = "
_mYWeeirT_emp8: .long	0
_15: .long	15
_p2: .long	0
_p3: .long	0
_'a': 	.byte 'a'
_n: .string	"\n"
_function_Return: .long	0
.section .rodata
