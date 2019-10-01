.global main
.data
fmt : .string "res x=%i y=%i\n"
.text
main:

mov $2, %rdi
mov $-10, %rsi
call foo
sub $8, %rsp
lea fmt(%rip), %rdi
mov (%rax), %rsi
add $8, %rax
mov (%rax), %rdx
call printf
add $8, %rsp

xor %eax, %eax
ret
