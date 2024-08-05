#include<stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int n,temp;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    int a[n],i,j;
    for(i=0;i<n;i++){
        printf("Enter a number: ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        insertionSort(a,n);
    }
    printf("The numbers in ascending order: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}