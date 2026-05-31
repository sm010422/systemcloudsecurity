	.build_version macos, 26, 0	sdk_version 26, 5
	.syntax	unified
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_foo                            @ -- Begin function foo
	.p2align	2
	.code	32
_foo:                                   @ @foo
@ %bb.0:
	push	{r7, lr}
	mov	r7, sp
	sub	sp, sp, #8
	str	r0, [sp, #4]
	ldr	r0, [sp, #4]
	str	r0, [sp]
	ldr	r1, [sp]
	ldr	r0, LCPI0_0
LPC0_0:
	add	r0, pc, r0
	bl	_printf
	mov	sp, r7
	pop	{r7, lr}
	bx	lr
	.p2align	2
@ %bb.1:
	.data_region
LCPI0_0:
	.long	L_.str-(LPC0_0+8)
	.end_data_region
                                        @ -- End function
	.globl	_bar                            @ -- Begin function bar
	.p2align	2
	.code	32
_bar:                                   @ @bar
@ %bb.0:
	push	{r7, lr}
	mov	r7, sp
	sub	sp, sp, #4
	mov	r0, #5
	str	r0, [sp]
	ldr	r0, [sp]
	bl	_foo
	mov	sp, r7
	pop	{r7, lr}
	bx	lr
                                        @ -- End function
	.globl	_main                           @ -- Begin function main
	.p2align	2
	.code	32
_main:                                  @ @main
@ %bb.0:
	push	{r7, lr}
	mov	r7, sp
	sub	sp, sp, #8
	mov	r0, #0
	str	r0, [sp]                        @ 4-byte Spill
	str	r0, [sp, #4]
	bl	_bar
	ldr	r0, [sp]                        @ 4-byte Reload
	mov	sp, r7
	pop	{r7, lr}
	bx	lr
                                        @ -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 @ @.str
	.asciz	"a = %d\n"

.subsections_via_symbols
