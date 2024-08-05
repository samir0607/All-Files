#include<stdio.h>
int main(){
    int n,i,a=0,b=1,num;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        if(i==0)
        printf("%d ",a);
        if(i==1)
        printf("%d ",b);
        if(i>=2){
            num=a+b;
            a=b;
            b=num;
            printf("%d ",num);
        }
    }
    return 0;
}