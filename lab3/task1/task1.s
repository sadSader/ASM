.globl foo;
//4 -4x
//4*(1-x)
foo: 
//rdi
mov $1, %rax
sub %rdi, %rax
shl $2, %rax /*rax*=4*/
ret
