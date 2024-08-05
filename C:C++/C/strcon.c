#include<stdio.h>
#include<string.h>
int main(){
    char a[100],b[100],c[100];

    int n,m;
    printf("Enter a string: ");
    fflush(stdin);
    gets(a);
    printf("Enter a string: ");
    fflush(stdin);
    gets(b);
    n=strlen(a);
    m=strlen(b);
    for(int i=0;i<n;i++){
        c[i]=c[i]+a[i];
    }
    for(int i=n,k=0;i<m+n;i++,k++){
        c[i]=c[i]+b[i];
    }
    printf("Concatinated word: %s",c);
    return 0;
}