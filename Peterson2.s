	.file	"Peterson2.cpp"
	.intel_syntax noprefix
# GNU C++ (Ubuntu 5.4.1-2ubuntu1~16.04) version 5.4.1 20160904 (x86_64-linux-gnu)
#	compiled by GNU C version 5.4.1 20160904, GMP version 6.1.0, MPFR version 3.1.4, MPC version 1.0.3
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE Peterson2.cpp
# -masm=intel -mtune=generic -march=x86-64 -O0 -fverbose-asm
# -fstack-protector-strong -Wformat -Wformat-security
# options enabled:  -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fexceptions -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
# -finline-atomics -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpeephole -fprefetch-loop-arrays
# -freg-struct-return -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fsigned-zeros
# -fsplit-ivs-in-unroller -fstack-protector-strong -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
# -ftree-coalesce-vars -ftree-cselim -ftree-forwprop -ftree-loop-if-convert
# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
# -ftree-parallelize-loops= -ftree-phiprop -ftree-reassoc -ftree-scev-cprop
# -funit-at-a-time -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mtls-direct-seg-refs -mvzeroupper

	.globl	tid1
	.bss
	.align 8
	.type	tid1, @object
	.size	tid1, 8
tid1:
	.zero	8
	.globl	tid2
	.align 8
	.type	tid2, @object
	.size	tid2, 8
tid2:
	.zero	8
	.globl	Gsem
	.align 32
	.type	Gsem, @object
	.size	Gsem, 32
Gsem:
	.zero	32
	.globl	Gk
	.align 4
	.type	Gk, @object
	.size	Gk, 4
Gk:
	.zero	4
	.globl	Gn
	.align 4
	.type	Gn, @object
	.size	Gn, 4
Gn:
	.zero	4
	.globl	GTurn
	.align 4
	.type	GTurn, @object
	.size	GTurn, 4
GTurn:
	.zero	4
	.globl	GWant
	.type	GWant, @object
	.size	GWant, 2
GWant:
	.zero	2
	.section	.rodata
.LC0:
	.string	"pid %d  tid %d\n"
	.text
	.globl	_Z12doSomeThing0Pv
	.type	_Z12doSomeThing0Pv, @function
_Z12doSomeThing0Pv:
.LFB11:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	push	rbx	#
	sub	rsp, 40	#,
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-40], rdi	# aid, aid
	call	pthread_self	#
	mov	ebx, eax	# D.5136, D.5135
	call	getpid	#
	mov	edx, ebx	#, D.5136
	mov	esi, eax	#, D.5136
	mov	edi, OFFSET FLAT:.LC0	#,
	mov	eax, 0	#,
	call	printf	#
	mov	QWORD PTR [rbp-24], 0	# i,
	mov	QWORD PTR [rbp-24], 0	# i,
.L7:
	cmp	QWORD PTR [rbp-24], 1221999	# i,
	ja	.L2	#,
	mov	BYTE PTR GWant[rip], 1	# GWant,
	mov	DWORD PTR GTurn[rip], 1	# GTurn,
.L6:
	movzx	eax, BYTE PTR GWant[rip+1]	# D.5134, GWant
	test	al, al	# D.5134
	je	.L3	#,
	mov	eax, DWORD PTR GTurn[rip]	# D.5136, GTurn
	cmp	eax, 1	# D.5136,
	jne	.L3	#,
	mov	eax, 1	# D.5134,
	jmp	.L4	#
.L3:
	mov	eax, 0	# D.5134,
.L4:
	test	al, al	# D.5134
	je	.L5	#,
	jmp	.L6	#
.L5:
	mov	eax, DWORD PTR Gn[rip]	# D.5136, Gn
	add	eax, 1	# D.5136,
	mov	DWORD PTR Gn[rip], eax	# Gn, D.5136
	mov	BYTE PTR GWant[rip], 0	# GWant,
	add	QWORD PTR [rbp-24], 1	# i,
	jmp	.L7	#
.L2:
	mov	eax, 0	# D.5137,
	add	rsp, 40	#,
	pop	rbx	#
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	_Z12doSomeThing0Pv, .-_Z12doSomeThing0Pv
	.globl	_Z12doSomeThing1Pv
	.type	_Z12doSomeThing1Pv, @function
_Z12doSomeThing1Pv:
.LFB12:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	push	rbx	#
	sub	rsp, 40	#,
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-40], rdi	# aid, aid
	call	pthread_self	#
	mov	ebx, eax	# D.5141, D.5140
	call	getpid	#
	mov	edx, ebx	#, D.5141
	mov	esi, eax	#, D.5141
	mov	edi, OFFSET FLAT:.LC0	#,
	mov	eax, 0	#,
	call	printf	#
	mov	QWORD PTR [rbp-24], 0	# i,
	mov	QWORD PTR [rbp-24], 0	# i,
.L15:
	cmp	QWORD PTR [rbp-24], 1221999	# i,
	ja	.L10	#,
	mov	BYTE PTR GWant[rip+1], 1	# GWant,
	mov	DWORD PTR GTurn[rip], 0	# GTurn,
.L14:
	movzx	eax, BYTE PTR GWant[rip]	# D.5139, GWant
	test	al, al	# D.5139
	je	.L11	#,
	mov	eax, DWORD PTR GTurn[rip]	# D.5141, GTurn
	test	eax, eax	# D.5141
	jne	.L11	#,
	mov	eax, 1	# D.5139,
	jmp	.L12	#
.L11:
	mov	eax, 0	# D.5139,
.L12:
	test	al, al	# D.5139
	je	.L13	#,
	jmp	.L14	#
.L13:
	mov	eax, DWORD PTR Gn[rip]	# D.5141, Gn
	sub	eax, 1	# D.5141,
	mov	DWORD PTR Gn[rip], eax	# Gn, D.5141
	mov	BYTE PTR GWant[rip+1], 0	# GWant,
	add	QWORD PTR [rbp-24], 1	# i,
	jmp	.L15	#
.L10:
	mov	eax, 0	# D.5142,
	add	rsp, 40	#,
	pop	rbx	#
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	_Z12doSomeThing1Pv, .-_Z12doSomeThing1Pv
	.section	.rodata
.LC1:
	.string	"\nInicialmente = %d\n"
.LC2:
	.string	"erro1"
.LC3:
	.string	"erro2"
.LC4:
	.string	"\nexecutando\n"
	.align 8
.LC5:
	.string	"\nResultado Final = %d       %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	mov	eax, 0	# D.5143,
	mov	BYTE PTR GWant[rip+1], al	# GWant, D.5143
	mov	BYTE PTR GWant[rip], al	# GWant, D.5143
	mov	eax, DWORD PTR Gn[rip]	# D.5144, Gn
	mov	esi, eax	#, D.5144
	mov	edi, OFFSET FLAT:.LC1	#,
	mov	eax, 0	#,
	call	printf	#
	mov	ecx, 0	#,
	mov	edx, OFFSET FLAT:_Z12doSomeThing0Pv	#,
	mov	esi, 0	#,
	mov	edi, OFFSET FLAT:tid1	#,
	call	pthread_create	#
	test	eax, eax	# D.5144
	setne	al	#, D.5143
	test	al, al	# D.5143
	je	.L18	#,
	mov	edi, OFFSET FLAT:.LC2	#,
	call	puts	#
.L18:
	mov	ecx, 1	#,
	mov	edx, OFFSET FLAT:_Z12doSomeThing1Pv	#,
	mov	esi, 0	#,
	mov	edi, OFFSET FLAT:tid2	#,
	call	pthread_create	#
	test	eax, eax	# D.5144
	setne	al	#, D.5143
	test	al, al	# D.5143
	je	.L19	#,
	mov	edi, OFFSET FLAT:.LC3	#,
	call	puts	#
.L19:
	mov	edi, OFFSET FLAT:.LC4	#,
	call	puts	#
	mov	rax, QWORD PTR tid1[rip]	# D.5145, tid1
	mov	esi, 0	#,
	mov	rdi, rax	#, D.5145
	call	pthread_join	#
	mov	rax, QWORD PTR tid2[rip]	# D.5145, tid2
	mov	esi, 0	#,
	mov	rdi, rax	#, D.5145
	call	pthread_join	#
	mov	edx, DWORD PTR Gk[rip]	# D.5144, Gk
	mov	eax, DWORD PTR Gn[rip]	# D.5144, Gn
	mov	esi, eax	#, D.5144
	mov	edi, OFFSET FLAT:.LC5	#,
	mov	eax, 0	#,
	call	printf	#
	mov	eax, 0	# D.5144,
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
