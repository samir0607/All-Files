#include<stdio.h>
int main(){
    int arr1[5]={1,2,3,4,5},arr2[5]={4,6,8,10,3};
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(arr1[i]==arr2[j]){
                printf("%d\t",arr1[i]);
            }
        }
    }
    return 0;
}