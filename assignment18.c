#include <stdio.h>
#include <string.h>

// function to reverse string
void reverse(char str[]) {
    int len = strlen(str);
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// function to check palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    // length
    printf("\nLength of s1 = %lu", strlen(s1));
    printf("\nLength of s2 = %lu", strlen(s2));

    // reverse
    printf("\nReverse of s1 = ");
    reverse(s1);
    printf("\nReverse of s2 = ");
    reverse(s2);

    // equality check
    if(strcmp(s1, s2) == 0)
        printf("\nStrings are equal");
    else
        printf("\nStrings are not equal");

    // palindrome check
    if(isPalindrome(s1))
        printf("\ns1 is palindrome");
    else
        printf("\ns1 is not palindrome");

    if(isPalindrome(s2))
        printf("\ns2 is palindrome");
    else
        printf("\ns2 is not palindrome");

    // substring check
    if(strstr(s1, s2) != NULL)
        printf("\ns2 is substring of s1");
    else
        printf("\ns2 is not substring of s1");

    return 0;
}
