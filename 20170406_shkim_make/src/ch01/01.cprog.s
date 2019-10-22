	.file	"01.cprog.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	10
	.comm	b,4,4
	.globl	a2
	.align 4
	.type	a2, @object
	.size	a2, 4
a2:
	.long	20
	.comm	b2,4,4
	.text
	.globl	f1
	.type	f1, @function
f1:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	addl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	f1, .-f1
	.section	.rodata
.LC0:
	.string	"hello"
	.align 8
.LC1:
	.string	"addr(TEXT)=> main:%p, f1:%p, f2:%p\n"
.LC2:
	.string	"addr(CONST)=> d:%p\n"
.LC3:
	.string	"addr(DATA)=> a:%p, a2:%p\n"
.LC4:
	.string	"addr(BSS)=> b:%p, b2:%p\n"
.LC5:
	.string	"addr(STACK)=> c:%p, c2:%p\n"
	.align 8
.LC6:
	.string	"addr(HEAP)=> name:%p, score:%p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$100, -28(%rbp)
	movq	$.LC0, -8(%rbp)
	movl	$50, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	movl	$80, %edi
	call	malloc
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movl	$f2, %ecx
	movl	$f1, %edx
	movl	$main, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$a2, %edx
	movl	$a, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$b2, %edx
	movl	$b, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	leaq	-32(%rbp), %rdx
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.globl	f2
	.type	f2, @function
f2:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	subl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	f2, .-f2
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
