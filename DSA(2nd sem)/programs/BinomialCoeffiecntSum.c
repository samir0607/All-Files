#include<stdio.h>
int fact(int a){
    if(a==0)
    return 1;
    else
    return fact(a-1) * a;
}

int main(){
    int n;
    int SumOfCoeff;
    printf("enter n: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        SumOfCoeff += fact(n)/(fact(n-i)*fact(i));
    }
    printf("Sum of coeff: %d",SumOfCoeff);
    return 0;
}