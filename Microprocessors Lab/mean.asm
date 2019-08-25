;Write 80387 ALP to obtain:;i) Mean ii) Variance iii) Standard Deviation



%macro print 2
mov rax, 01
mov rdi, 01
mov rsi, %1
mov rdx, %2
syscall
%endmacro



section .data

m0 db 10,13,"80387 Coprocessor to calculate Mean, Variance and Standard Deviation",10
l0 equ $-m0

m1 db 10,13,"Array Elements: 102.59, 198.21, 100.67",10
l1 equ $-m1

m2 db 10,13,"Mean :"
l2 equ $-m2

m3 db 10,13,"Variance :"
l3 equ $-m3

m4 db 10,13,"Standard Deviation :"
l4 equ $-m4

newline db 0xa

num1 dd 102.59
num2 dd 198.21
num3 dd 100.67

num4 dd 03.00

dpoint db "."

hdec dq 100


section .bss

dispbuff resb 1

resbuff resb 10

mean resd 1

variance resd 1


section .text
global _start
_start:


print m0,l0

print m1,l1

finit
fldz

;Logic to calculate MEAN


fld dword[num1]	;Ist no. on x387 stack top
fld dword[num2]	;IInd no. on x387 stack top

fadd st0,st1	;(num1 + num2) at stack top

fld dword[num3]	;IIIrd no. on x387 stack top

fadd st0,st1		;Array addition on x387 ST0

fdiv dword[num4]  ;ST0 = Addition /3 = Mean

fst dword[mean]		;Store ST0 to variable mean
 
print m2,l2
call disp_result

print newline,01

;Logic to calculate Variance = (num - mean)^2

mov rsi,num1
call cal_diff_sqr

mov rsi,num2
call cal_diff_sqr

fadd st0,st1		;Add num1 & num2 squares

mov rsi,num3
call cal_diff_sqr

fadd st0,st1		;Add (num1+ num2) and num3 squares

fdiv dword[num4]	;divide by cardinality

fst dword[variance]	;store variance at ST(0) = variable "variance"

print m3,l3
call disp_result

print newline,01

;Logic to calculate Standard Deviation

fld dword[variance]
fsqrt

print m4,l4
call disp_result

print newline,01



mov rax,60
xor rdi,rdi
syscall



disp_result:
	fimul dword[hdec]
	fbstp [resbuff]		;Store BCD and pop

	xor rcx,rcx
	mov rcx,09h
	mov rsi,resbuff+09	;rsi pointing to MSB of Result


up2:
	push rcx
	push rsi

	mov bl,[rsi]
	call disp8_proc

	print dispbuff,02

	pop rsi
	dec rsi
	pop rcx
	loop up2

	print dpoint,01

	mov bl,[resbuff]
	call disp8_proc

    print dispbuff,02

ret


;Hex number to its equivalent ASCII conversion
disp8_proc:
	mov rdi,dispbuff
	mov rcx,02
back:
	rol bl,04
	mov dl,bl
	and dl,0Fh
	cmp dl,09h
	jbe skip
	add dl,07h
skip:
	add dl,30h
	mov [rdi],dl
	inc rdi
	loop back
	ret


cal_diff_sqr:
	fld dword[rsi]
	fsub dword[mean]
	fmul st0,st0
	ret


