#include <stdio.h>
#include <string.h>
int main() {
    char firstString[100];
    char secondString[100];
    printf("Enter the first string: ");
    fgets(firstString, sizeof(firstString), stdin);
    firstString[strcspn(firstString, "\n")] = '\0';
    printf("Enter the second string: ");
    fgets(secondString, sizeof(secondString), stdin);
    secondString[strcspn(secondString, "\n")] = '\0';
    strcat(firstString, secondString);
    printf("Concatenated string: %s\n", firstString);
    return 0;
}
