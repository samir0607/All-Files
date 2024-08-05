#include <stdio.h>

int main() {
    int a,b,c;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Enter the third number: ");
    scanf("%d", &c);
    printf("(a == b) && (c > b) is %s\n",(a==b) && (c>b) ? "true" : "false");
    printf("(a == b) && (c < b) is %s\n",(a==b) && (c<b) ? "true" : "false");
    printf("(a == b) || (c < b) is %s\n",(a==b) || (c<b) ? "true" : "false");
    printf("(a != b) || (c < b) is %s\n",(a!=b) || (c<b) ? "true" : "false");
    return 0;
}
