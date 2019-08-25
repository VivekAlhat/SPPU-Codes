%macro scall 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
	title: db 10,'Multiplication of two hex numbers using various techniques',10
	title_len: equ $- title
	
	m:    db 10,'1.Successive addition method',10
	      db 10,'2.Add and shift method',10
	      db 10,'3.Exit',10
	      db 10,'Enter your choice:',10
	m_len: equ $- m
	
	fnumber: db 10,'Enter the first number:',10
	fnumber_len: equ $- fnumber
	
	snumber: db 10,'Enter the second number:',10
	snumber_len: equ $- snumber
	
	result: db 10,'Result:',10
	result_len: equ $- result
	
section .bss
	n: resb 4	;take input from user and display output
	num1: resb 1	
	num2: resb 1
	choice: resb 2
	
section .text
	global _start
	_start:
		scall 1,1,title,title_len
		menu:
			scall 1,1,m,m_len
			scall 0,0,choice,2
			
			case1:
				cmp byte[choice],'1'
				jne case2
				scall 1,1,fnumber,fnumber_len
				scall 0,0,n,3
				call atoh
				mov [num1],bl
				
				scall 1,1,snumber,snumber_len
				scall 0,0,n,3
				call atoh
				mov [num2],bl
				
				call p1
				jmp menu
				
			case2:
				cmp byte[choice],'2'
				jne case3
				scall 1,1,fnumber,fnumber_len
				scall 0,0,n,3
				call atoh
				mov [num1],bl
				
				scall 1,1,snumber,snumber_len
				scall 0,0,n,3
				call atoh
				mov [num2],bl
				
				call p2
				jmp menu
				
			case3:
				cmp byte[choice],'3'
				jne exit
				
		exit:
			mov rax,60
			mov rdi,0
			syscall
					
		p1:
			mov rax,0
			mov rbx,0
			mov rcx,0
			mov al,[num1]
			mov cl,[num2]
			lp2:
			add bx,ax
			loop lp2
			scall 1,1,result,result_len
			call displaynum
			ret
			
		p2:
			mov rbx,0
			mov rcx,0
			mov rdx,0 
			mov al,[num1]
			mov bl,[num2]
			mov rcx,8
			lp4:
			shr bl,1
			jnc flag
			add dx,ax
			flag:
			shl ax,1
			loop lp4
			mov rbx,rdx
			scall 1,1,result,result_len
			call displaynum
			ret
			
		displaynum:
			mov rcx,4
			mov rax,0
			mov rsi,n
			lp3:
				rol bx,4
				mov al,bl
				and al,0FH
				cmp al,09H
				jbe add30
				add al,07H
				add30:
				add al,30H
				mov [rsi],al
				inc rsi
			loop lp3
			scall 1,1,n,4
			ret
		
		atoh:
			mov rsi,n
			mov rax,0
			mov rbx,0
			mov rcx,2
			lp1:
				rol bl,4
				mov al,[rsi]
				cmp al,39H
				jbe sub30
				sub al,07H
				sub30:
				sub al,30H
				add bl,al
				inc rsi
			loop lp1
			ret
			
