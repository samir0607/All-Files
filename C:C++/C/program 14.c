#include <stdio.h>
int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Print 'Hello'\n");
    printf("2. Print 'Goodbye'\n");
    printf("3. Print 'Welcome'\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Hello\n");
            break;
        case 2:
            printf("Goodbye\n");
            break;
        case 3:
            printf("Welcome\n");
            break;
        case 4:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}
