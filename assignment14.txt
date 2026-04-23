#include <stdio.h>
#include <math.h>

int main() {
    int binary, decimal = 0, i = 0, rem;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while(binary != 0) {
        rem = binary % 10;
        decimal += rem * pow(2, i);
        binary = binary / 10;
        i++;
    }

    printf("Decimal = %d", decimal);

    return 0;
}
