#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    while(num != 0) {
        int last_digit = num % 10;
        printf("%d ", last_digit);
        num = num / 10;
    }

    return 0;
}
