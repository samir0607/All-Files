#include<stdio.h>
int fact(int n);

int main(){
    int n,a;
    printf("Enter a number: ");
    scanf("%d",&n);
    a=fact(n);
    printf("%d!=%d",n,a);
    return 0;
}

int fact(n){
    if(n<=1)
        return 1;
    else
        return n*fact(n-1);
}
