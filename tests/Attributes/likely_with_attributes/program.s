	.file	"program.cpp"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB2195:
	.cfi_startproc
	endbr64
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE2195:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.text._Z3powdi,"axG",@progbits,_Z3powdi,comdat
	.p2align 4
	.weak	_Z3powdi
	.type	_Z3powdi, @function
_Z3powdi:
.LFB2448:
	.cfi_startproc
	endbr64
	testl	%edi, %edi
	jle	.L13
	movapd	%xmm0, %xmm1
	cmpl	$1, %edi
	je	.L14
	cmpl	$2, %edi
	je	.L29
	cmpl	$3, %edi
	je	.L28
	cmpl	$4, %edi
	je	.L27
	cmpl	$5, %edi
	je	.L26
	cmpl	$6, %edi
	je	.L25
	cmpl	$7, %edi
	je	.L24
	cmpl	$8, %edi
	je	.L21
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	subl	$9, %edi
	movsd	%xmm0, 8(%rsp)
	call	_Z3powdi
	movsd	8(%rsp), %xmm1
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	ret
	.p2align 4,,10
	.p2align 3
.L21:
	mulsd	%xmm0, %xmm0
.L24:
	mulsd	%xmm1, %xmm0
.L25:
	mulsd	%xmm1, %xmm0
.L26:
	mulsd	%xmm1, %xmm0
.L27:
	mulsd	%xmm1, %xmm0
.L28:
	mulsd	%xmm1, %xmm0
.L29:
	mulsd	%xmm1, %xmm0
	ret
	.p2align 4,,10
	.p2align 3
.L13:
	movsd	.LC0(%rip), %xmm0
	ret
	.p2align 4,,10
	.p2align 3
.L14:
	ret
	.cfi_endproc
.LFE2448:
	.size	_Z3powdi, .-_Z3powdi
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"With attributes: "
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB2449:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	leaq	.LC1(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movsd	.LC2(%rip), %xmm0
	movl	$10, %edi
	movq	%rax, %rbp
	call	_Z3powdi
	movq	%rbp, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %r12
	testq	%r12, %r12
	je	.L39
	cmpb	$0, 56(%r12)
	je	.L35
	movsbl	67(%r12), %esi
.L36:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L35:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	movl	$10, %esi
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L36
	movl	$10, %esi
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L36
.L39:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE2449:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB3024:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE3024:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.align 8
.LC2:
	.long	0
	.long	1073741824
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
