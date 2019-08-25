%macro scall 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
	pmsg: db 10,'Positive count is:',10
	pmsg_len: equ $- pmsg
	
	nmsg: db 10,'Negative count is:',10
	nmsg_len: equ $- nmsg
	
	pcount: db 0
	ncount: db 0
	
	array: dw 9000h,8001h,9002h,4553h,8006h,9004h,022h
	newline: db 10
	
section .bss
	dbuff: resb 2
	
section .text
	global _start
	_start:
		mov rsi,array
		mov ecx,7
	again:
		bt word[rsi],15
		jnc pnext
		inc byte[ncount]
		jmp pskip
		
	pnext:	inc byte[pcount]
		
	pskip:	inc rsi	
		inc rsi
		loop again
		
		scall 1,1,pmsg,pmsg_len
		mov bl,[pcount]
		call display
		scall 1,1,nmsg,nmsg_len
		mov bl,[ncount]
		call display
		scall 1,1,newline,1

	exit:
		mov rax,60
		mov rdi,0
		syscall
		
	display:		;hex to ascii
		mov rcx,16 
		mov rdi,dbuff
	up1:
		rol bl,4
		mov al,bl
		and al,0fh
		cmp al,09
		jbe skip
		add al,07h	
	skip:	
		add al,30h
		mov [rdi],al
		inc rdi
		loop up1
		scall 1,1,dbuff,2
		ret
