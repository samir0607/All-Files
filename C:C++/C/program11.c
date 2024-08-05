#include <stdio.h>
void printHalfPyramid(int rows) {
    int i, j;
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
void printInvertedHalfPyramid(int rows) {
    int i, j;
    for (i = rows; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
void printHollowInvertedHalfPyramid(int rows) {
    int i, j;
    for (i = rows; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == rows) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}
void printFullPyramid(int rows) {
    int i, j, space;
    for (i = 1; i <= rows; i++) {
        for (space = 1; space <= rows - i; space++) {
            printf("  ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
void printInvertedFullPyramid(int rows) {
    int i, j, space;
    for (i = rows; i >= 1; i--) {
        for (space = 1; space <= rows - i; space++) {
            printf("  ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
void printHollowFullPyramid(int rows) {
    int i, j, space;
    for (i = 1; i <= rows; i++) {
        for (space = 1; space <= rows - i; space++) {
            printf("  ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1 || i == rows) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}
int main() {
    int choice, rows;

    do {
        printf("Choose a pattern to print:\n");
        printf("1. Half Pyramid\n");
        printf("2. Inverted Half Pyramid\n");
        printf("3. Hollow Inverted Half Pyramid\n");
        printf("4. Full Pyramid\n");
        printf("5. Inverted Full Pyramid\n");
        printf("6. Hollow Full Pyramid\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 7) {
            printf("Exiting the program.\n");
            break;
        }
        printf("Enter the number of rows: ");
        scanf("%d", &rows);

        switch (choice) {
            case 1:
                printHalfPyramid(rows);
                break;
            case 2:
                printInvertedHalfPyramid(rows);
                break;
            case 3:
                printHollowInvertedHalfPyramid(rows);
                break;
            case 4:
                printFullPyramid(rows);
                break;
            case 5:
                printInvertedFullPyramid(rows);
                break;
            case 6:
                printHollowFullPyramid(rows);
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (1);
    return 0;
}

