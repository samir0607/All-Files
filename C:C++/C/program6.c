#include <stdio.h>
int main() 
{
    int num, digit, sum = 0;
    printf("Enter a 3-digit number: ");
    scanf("%d", &num);
    if (num < 100 || num > 999) {
        printf("Invalid input. Please enter a 3-digit number.\n");
        return 1;
    }
    digit = num % 10;
    sum += digit;
    num /= 10;
    digit = num % 10;
    sum += digit;
    num /= 10;
    digit = num % 10;
    sum += digit;
    printf("The sum of the digits is: %d\n", sum);
    return 0;
}
