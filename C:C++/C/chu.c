#include<stdio.h>
int main(){
    int a=5,b=7,c,d, e=7;

    c= a+ ++b;
    d = a+e++;
    printf("%d %d", c,d);
    return 0;
}