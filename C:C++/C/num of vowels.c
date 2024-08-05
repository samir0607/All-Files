#include<stdio.h>
#include<string.h>
int main(){
    int i,n,c=0;
    char a[20];
    printf("Enter a word: ");
    scanf("%s",&a);
    n=strlen(a);
    for(i=0;i<n;i++){
        switch(a[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            c++;
            break;
        }
    }
    printf("Number of vowels: %d",c);
    return 0;
}