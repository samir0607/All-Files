#include<stdio.h>
int main(){
    int c;
    int* pc;
    c=11;
    printf("%d\n",c);
    printf("%p\n\n",&c);

    pc=&c;
    printf("%p\n",pc);
    printf("%d\n\n",*pc);
    
    c=2;
    printf("%p\n",pc);
    printf("%d\n\n",*pc);
    *pc=22;
    printf("%d\n",c);
    printf("%p\n\n",&c);
    return 0;

}