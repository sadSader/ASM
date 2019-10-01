//x=a^2-b^2
//y=2ab

//rdi
//rsi
.global foo
.text
foo:
mov %rdi, %rax
mul %rsi
shl $1, %rax
push %rax

mov %rdi, %rax
mul %rax
mov %rax, %rcx /* rcx= a^2  */
mov %rsi, %rax
mul %rax
sub %rax, %rcx  /* rcx=a^2-b^2=x*/
push %rcx

mov $16, %rdi /* 2*8 */
call malloc
pop %rbx
mov %rbx, (%rax)
add $8, %rax 

pop %rbx
mov %rbx, (%rax)  

sub $8, %rax 
ret

//Wrong
//mov %rdi, %rax
//mov %rsi, %rcx
//mul %rax, %rax
//mul %rsi, %rsi
//sub %rsi, %rax /*a^2-b^2*/

//Wrong

ret
