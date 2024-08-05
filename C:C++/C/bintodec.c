#include <stdio.h>
#include <math.h>
void decimalToBinary(int decimal) {
    int binary[32];
    int index = 0;
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }
    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}
void binaryToDecimal(long long binary) {
    int decimal = 0, base = 1, remainder;
    while (binary > 0) {
        remainder = binary % 10;
        decimal = decimal + remainder * base;
        binary = binary / 10;
        base = base * 2;
    }
    printf("Decimal: %d\n", decimal);
}
int main() {
    int choice;
    long long binary;
    int decimal;
    printf("Choose an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        }
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%lld", &binary);
                binaryToDecimal(binary);
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}

