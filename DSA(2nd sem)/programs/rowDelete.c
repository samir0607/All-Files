#include<stdio.h>
#define ROW 3
#define COL 4
void display(int arr[][COL],int rows){
    for(int i = 0; i < rows; i++){
        for(int j=0; j < COL; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
void deleteRow(int arr[][COL],int *rows, int index){
    if(index<0 || index >= *rows){
        printf("Invalid row index\n");
        return;
    }
    for(int i = index; i<*rows-1; i++){
        for(int j=0; j<COL; j++){
            arr[i][j] = arr[i+1][j];
        }
    }
    (*rows)--;
}
int main(){
    int rows = ROW;
    int arr[ROW][COL]= {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12}};
    printf("Original Array:\n");
    display(arr, rows);
    deleteRow(arr, &rows, 1);
    printf("\nAfter deleting row 1:\n");
    display(arr, rows);
    return 0;
}
