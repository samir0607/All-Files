#include <stdio.h>

int main() {
    int num, digit, sum = 0;

    // Input a number from the user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Ensure the number is non-negative
    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Calculate the sum of digits using a for loop
    for (; num > 0; num /= 10) {
        digit = num % 10; // Get the last digit
        sum += digit;     // Add it to the sum
    }

    printf("The sum of digits is: %d\n", sum);

    return 0;
}
