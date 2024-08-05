#include <stdio.h>
int main() 
{
    unsigned int a = 5;
    unsigned int b = 3;
    unsigned int result_and = a & b;
    printf("a & b = %u\n", result_and);
    unsigned int result_or = a | b;
    printf("a | b = %u\n", result_or);
    unsigned int result_xor = a ^ b;
    printf("a ^ b = %u\n", result_xor);
    unsigned int result_not_a = ~a;
    printf("~a = %u\n", result_not_a);
    unsigned int result_left_shift = a << 1;
    printf("a << 1 = %u\n", result_left_shift);
    unsigned int result_right_shift = b >> 1;
    printf("b >> 1 = %u\n", result_right_shift);
    return 0;
}
