#include <stdio.h>

int binaryToDecimal(long binary) {
    int decimal = 0, base = 1, remainder;

    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }

    return decimal;
}

int main() {
    long binaryInput;
    printf("Enter a binary number: ");
    scanf("%ld", &binaryInput);

    int decimalResult = binaryToDecimal(binaryInput);
    printf("Decimal equivalent: %d\n", decimalResult);

    return 0;
}