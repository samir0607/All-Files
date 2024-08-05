#include<stdio.h>
int main(){
    int a=0;
    int b=10;
    int c=20;
    int d=a&&++b&&++c;
    printf("%d %d %d %d",a,b,c,d);
    return 0;
}