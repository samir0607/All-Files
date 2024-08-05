#include<stdio.h>
int main(){
    int n,rev;
    printf("Enter a 3-digit number: ");
    scanf("%d",&n);
        if (n < 100 || n > 999) {
        printf("Invalid input. Please enter a 3-digit number.\n");
        return 1;
    }
    while(n!=0){
        rev = rev*10 + n%10;
        n=n/10;
    }
    printf("Reverse is %d",rev);
    return 0;
}