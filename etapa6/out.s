.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"

## VAR DECLARATION
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	_7(%rip), %eax
	movl	%eax, _x(%rip)
	call	_main
## TAC_ENDFUN
	popq	%rbp
	ret


## TAC_BEGINFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

	leaq	_str0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_7: .long	7
_x: .long	0
_str0: .string	"oi \nisso aqui \n eh uma string\n"
.section .rodata
