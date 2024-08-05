#include <stdio.h>
#include <string.h>
int countVowels(const char *str) {
    int count = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char ch = tolower(str[i]); // Convert the character to lowercase for case-insensitivity
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    int vowels = countVowels(input);
    printf("Number of vowels in the string: %d\n", vowels);
    return 0;
}
