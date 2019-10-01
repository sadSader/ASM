#include <cstdio>
extern "C" size_t foo(size_t x);

int main()
{
    printf("foo(1) %li\n",foo(1));
    printf("foo(1) %li\n",foo(-1));
    printf("foo(1) %li\n",foo(-2));
    return 0;
}