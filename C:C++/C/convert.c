#include <stdio.h>
 
void convert(int m1[][10], int n, int m2[]) {
    int k = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            m2[k++] = m1[i][j];
        }
    }
}
int main() {
    int m1[10][10] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                    };
    int n = 3;
    int m2[10 * 10];
    convert(m1, n, m2);
    printf("Resultant 1D Array in column major form is : ");
    for (int i = 0; i < n * n; i++) {
        printf("%d ", m2[i]);
    }
    return 0;
}
