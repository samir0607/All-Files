#include<stdio.h>
int main(){
    int arr1[5]={1,2,3,4,5},arr2[5]={2,4,6,8,10};
    int i,j;
    int arr3[10];
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(arr1[i]==arr2[j]){
                arr3[i]=arr1[i];
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(arr1[i]!=arr2[j]){
                arr3[i+5]=arr1[i];
                arr3[i+6]=arr2[j];
            }
        }
    }
    int n = sizeof(arr3);
    for(i=0;i< n;i++){
        printf("%d",arr3[i]);
    }
    return 0;
}
