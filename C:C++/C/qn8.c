#include<stdio.h>
int main(){
    int n,i,a;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(int a=0;a<n;a++){
        for(i=n;i>a;i--){
            printf("%d",n-a);
        }
        for(i=1;i<a;i++){
            printf("%d",a-i+1);
        }
        for(i=1;i<=a;i++){
            printf("%d",i);
        }
        for(i=n;i>1;i--){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}