#include <stdio.h>

// Function prototype
void multiplyArray(int rows, int cols, int arr[][cols], int scalar, int result[][cols]);

int main() {
    // Example 2D array
    int array[3][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};

    // Scalar value
    int scalar = 2;

    // Result array
    int result[3][3];

    // Call the function
    multiplyArray(3, 3, array, scalar, result);

    // Display the original array
    printf("Original Array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }

    // Display the result array
    printf("\nArray after multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function definition
void multiplyArray(int rows, int cols, int arr[][cols], int scalar, int result[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = arr[i][j] * scalar;
        }
    }
}
