%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro
%macro read 2
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro


section .data
menumsg db 10,10,"*****menu for code converter****"
db 10,"1.hex to BCD"
db 10,"2.BCD to hex"
db 10,"3.exit"
db 10,10,"enter your choice"
menumsg_len equ $-menumsg

wromsg db 10,10,"wrong choice entered"
wromsg_len equ $-wromsg

hexmsg db 10,10,"enter the 4-digit hex number"
hexmsg_len equ $-hexmsg
hexmsg1 db 10,10,"equivalence BCD"
hexmsg1_len equ $-hexmsg1

bcdmsg db 10,10,"enter the 5-digit BCD number"
bcdmsg_len equ $-bcdmsg
bcdmsg1 db 10,10,"equivalence hex"
bcdmsg1_len equ $-bcdmsg1


section .bss
numascii resb 06
bcdbuff resb 05
hexbuff resb 05


section .text
global _start
_start:

print menumsg,menumsg_len
read numascii,2          
cmp byte[numascii],'1'
jne case2   
call hextobcd
jmp _start

case2:
cmp byte[numascii],'2'
jne case3
call bcdtohex
jmp _start

case3:
cmp byte[numascii],'3'
je exit
print wromsg,wromsg_len
jmp _start

exit:
mov rax,60
mov rdi,0
syscall

hextobcd:
print hexmsg,hexmsg_len
read numascii,05
call packnum
mov rcx,0
mov ax,bx
mov bx,10
loop1:
mov dx,0
div bx
push rdx
inc rcx
cmp ax,0
jne loop1
mov rdi,bcdbuff
loop2:
pop rdx
add dl,30h
mov[rdi],dl
inc rdi
loop loop2
print hexmsg,hexmsg_len
print bcdbuff,5
ret

bcdtohex:
print bcdmsg,bcdmsg_len
read numascii,6
print bcdmsg1,bcdmsg1_len
mov rsi,numascii
mov rcx,05
mov rax,0
mov rbx,0ah
b2hup1:
mov rdx,0
mul rbx
mov dl,[rsi]
sub dl,30h
add rax,rdx
inc rsi
loop b2hup1
mov rbx,rax
call dispnum_32
ret



packnum:
mov bx,0
mov rcx,04
mov rsi,numascii

up1:
rol bx,04
mov al,[rsi]
cmp al,39h
jbe skip1
sub al,07h

skip1:
sub al,30h
add bl,al
inc rsi
loop up1
ret



dispnum_32:
mov rdi,hexbuff
mov rcx,08

dispup1:
rol ebx,04
mov dl,bl
and dl,0fh
add dl,30h
cmp dl,39h
jbe diskip1
add dl,07h

diskip1:
mov [rdi],dl
inc rdi
loop dispup1
print hexbuff+3,5
ret



;admin1@admin:~/Desktop$ nasm -f elf64 hex.asm
;admin1@admin:~/Desktop$ ld -o hex hex.o
;admin1@admin:~/Desktop$ ./hex


;*****menu for code converter****
;1.hex to BCD
;2.BCD to hex
;3.exit

;enter your choice1


;enter the 4-digit hex numberFFFF


;enter the 4-digit hex number65535

;*****menu for code converter****
;1.hex to BCD
;2.BCD to hex
;3.exit

;enter your choice2


;enter the 5-digit BCD number65535


;equivalence hex0FFFF

;*****menu for code converter****
;1.hex to BCD
;2.BCD to hex
;3.exit

;enter your choice3
;admin1@admin:~/Desktop$ */

