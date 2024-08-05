#include <stdio.h>
 
int DSUM(int mat[][10], int row, int col) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == j) {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}
int main() {
    int mat[10][10] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                        };
    int row = 3;
    int col = 3;
    int result = DSUM(mat, row, col);
    printf("Sum of the Diagonal Elements in the given array is : %d", result);
    return 0;
}