#include<stdio.h>
int main(){
    char s1[20], s2[20], s3[20];
    printf("Enter string: ");
    scanf("%s",&s1);
    printf("Enter string: ");
    getchar();
    gets(s2);
    printf("Enter a string: ");
    fgets(s3,sizeof(s3), stdin);
    return 0;
}