#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];
    int choice, len, result;

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Find Length of First String\n");
        printf("2. Copy First String to Second\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Reverse First String\n");
        printf("6. Exit\n");
        printf("==========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                len = strlen(str1);
                printf("Length of first string: %d\n", len);
                break;

            case 2:
                strcpy(str2, str1);
                printf("After copying, second string: %s\n", str2);
                break;

            case 3:
                strcpy(temp, str1);  // preserve original
                strcat(temp, str2);
                printf("Concatenated string: %s\n", temp);
                break;

            case 4:
                result = strcmp(str1, str2);
                if(result == 0)
                    printf("Strings are equal\n");
                else if(result < 0)
                    printf("First string is smaller\n");
                else
                    printf("First string is greater\n");
                break;

            case 5: {
                int i, j;
                char rev[100];
                int length = strlen(str1);

                for(i = length - 1, j = 0; i >= 0; i--, j++) {
                    rev[j] = str1[i];
                }
                rev[j] = '\0';

                printf("Reversed string: %s\n", rev);
                break;
            }

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}
