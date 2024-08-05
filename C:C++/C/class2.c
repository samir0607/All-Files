#include<stdio.h>
int main(){
    int a=0;
    int b=10;
    int c=20;
    int d=a&&++b&&++c;
    printf("%d %d %d %d\n",a,b,c,d);
    a++;
    int e=a&&(++b>20)&&++c;
    printf("%d %d %d %d\n",a,b,c,e);
    int f=++a||(++b&&++c);
    printf("%d %d %d %d\n",a,b,c,f);
    a=a+++a;
    printf("%d",a);
    return 0;
}