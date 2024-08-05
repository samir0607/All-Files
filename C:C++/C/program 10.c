#include <stdio.h>
#include <string.h>
int main() {
    char s1[100];
    printf("Enter a string using scanf: ");
    scanf("%s", &s1);
    printf("String entered using scanf: %s\n", s1);
    while (getchar() != '\n');
    char s2[100];
    printf("Enter a string using gets: ");
    gets(s2);
    printf("String entered using gets: %s\n", s2);
    char s3[100];
    printf("Enter a string using fgets: ");
    fgets(s3, sizeof(s3), stdin);
    s3[strcspn(s3, "\n")] = '\0';
    printf("String entered using fgets: %s\n", s3);
    return 0;
}
