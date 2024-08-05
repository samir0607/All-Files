#include<stdio.h>
int main(){
    int n,temp;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    int a[n],i,j;
    for(i=0;i<n;i++){
        printf("Enter a number: ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The numbers in ascending order: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}