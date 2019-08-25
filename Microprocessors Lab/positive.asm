section .data

      pmsg db 0xa,'Count of positive numbers :'
      pmsg_len equ $ -pmsg

      nmsg db 0xa,'Count of negative numbers :'
      nmsg_len equ $ -nmsg

      newline db 0xa
      array dq 8080808080808505h,0c0c44290ffh,87h,88h,8a9fh,0adh,02h

      pcount db 0
      ncount db 0

section .bss 

      count resb 01
      count1 resb 01

%macro print 2

      mov rax,1
      mov rdi,1
      mov rsi,%1
      mov rdx,%2
      syscall

%endmacro

section .text
global _start
_start:

      mov rsi,array
      mov rcx,07

again :
      bt qword[rsi],63
      jnc pnxt
      inc byte[ncount]
      jmp pskip

pnxt:
      inc byte[pcount]

pskip:
      add rsi,64

      loop again

      print pmsg,pmsg_len

      mov bl,[pcount]
      call disp_result

      print nmsg,nmsg_len
      mov bl,[ncount]
      call disp_result

      print newline,1

exit:
      mov rax,60
      mov rdi,0
      syscall

disp_result:
      mov dl,bl
      and dl,0f0h
      rol dl,04
      cmp dl,09h
      jbe skip

      add dl,07h

skip:
      add dl,30h
   
      mov byte[count],dl

      and bl,0fh
      cmp bl,09h
      jbe skip1

      add bl,07h

skip1:
      add bl,30h
 
      mov byte[count1],bl
 
      print count,01
      print count1,01
ret

;output
;Count of positive numbers :06
;Count of negative numbers :01
