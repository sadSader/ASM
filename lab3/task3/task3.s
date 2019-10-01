.globl main
.data 
fmt: .string "read %lli\n"
main:
sub $8, %rsp
call scan
add $8, %rsp

//printf(fmt, rax)
sub $8, %rsp
lea fmt(%rip), %rdi
mov %rax, %rsi
call printf
add $8, %rsp

xor %eax, %eax
ret
