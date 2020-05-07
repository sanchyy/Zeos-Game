ENTRY(get_key)
    pushl %ebp
    movl %esp, %ebp
    movl $0x05, %eax # codi 5
    pushl %ecx
    pushl %edx
    pushl $retorn_getkey
    pushl %ebp  
    mov %esp, %ebp 
    sysenter

retorn_getkey:
    popl %ebp
    popl %ecx
    popl %edx
    popl %ecx 
    mov %ebp, %esp
    popl %ebp
    ret
    
    
ENTRY(get_put_screen)
    pushl %ebp
    movl %esp, %ebp
    movl $0x06, %eax # codi 5
    pushl %ecx
    pushl %edx
    pushl $retorn_put_screen
    pushl %ebp  
    mov %esp, %ebp 
    sysenter

retorn_put_screen:
    popl %ebp
    popl %ecx
    popl %edx
    popl %ecx 
    mov %ebp, %esp
    popl %ebp
    ret
