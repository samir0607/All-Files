#include<stdio.h>
int main(){
    float a,b;
    char oper;
    printf("Enter numbers: ");
    scanf("%f %f",&a,&b);
    printf("Enter[+,-,*,/]: ");
    getchar();
    scanf("%c",&oper);
    switch(oper){
        case '+':
        printf("Result=%f",a+b);
        break;
        case '-':
        printf("Result=%f",a-b);
        break;
        case '*':
        printf("Result=%f",a*b);
        break;
        case '/':
        if(b==0){
            printf("Error dividend can't be zero");
        }
        else{
        printf("Result=%f",a/b);
        break;
        }
        default:
        printf("Invalid");
    }
    return 0;
}
