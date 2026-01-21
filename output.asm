section .text
global _start
_start:
    mov eax, 10
    mov eax, 60
    xor edi, edi
    syscall
