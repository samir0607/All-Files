#include <stdio.h>

long decimalToBinary(int decimal) {
    long binary = 0;
    int remainder, base = 1;

    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

int main() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    long binaryNumber = decimalToBinary(decimalNumber);
    printf("Binary equivalent: %ld\n", binaryNumber);

    return 0;
}