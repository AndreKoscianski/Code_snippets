	.file	"cabum2.c"
	.intel_syntax noprefix
	.section .rdata,"dr"
LC0:
	.ascii "---ai caramba!\0"
LC1:
	.ascii "---danou-se!\0"
	.text
	.globl	_f
	.def	_f;	.scl	2;	.type	32;	.endef
_f:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_puts
/APP
 # 8 "cabum2.c" 1
	mov %ebp,666
 # 0 "" 2
 # 11 "cabum2.c" 1
	.intel_syntax
 # 0 "" 2
 # 12 "cabum2.c" 1
	pop eax
 # 0 "" 2
 # 13 "cabum2.c" 1
	.att_syntax
 # 0 "" 2
/NO_APP
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	_puts
	leave
	ret
	.section .rdata,"dr"
LC2:
	.ascii "-chamando f()!\0"
LC3:
	.ascii "-voltei!\0"
	.text
	.globl	_g
	.def	_g;	.scl	2;	.type	32;	.endef
_g:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	mov	DWORD PTR [esp], OFFSET FLAT:LC2
	call	_puts
	mov	DWORD PTR [esp], OFFSET FLAT:LC3
	call	_puts
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC4:
	.ascii "la vou eu\0"
LC5:
	.ascii "voltei\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	sub	esp, 16
	call	___main
	mov	DWORD PTR [esp], OFFSET FLAT:LC4
	call	_puts
	call	_f
	mov	DWORD PTR [esp], OFFSET FLAT:LC5
	call	_puts
	mov	eax, 0
	leave
	ret
	.def	_puts;	.scl	2;	.type	32;	.endef
