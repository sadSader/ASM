.globl main
.data
x: .long 13 
fmt: .string "f(13) = %li\n"

.text
main:
movslq x(%rip), %rdi
call foo

//printf(fmt, rax)
sub $8, %rsp
lea fmt(%rip), %rdi
mov %rax, %rsi
call printf
add $8, %rsp

xor %eax, %eax
ret
