#include <stdio.h>

int main() {
    int num1, num2, i, gcd, scd = -1;
    int a, b, temp;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    a = num1;
    b = num2;

    // Smallest Common Divisor (other than 1)
    for(i = 2; i <= num1 && i <= num2; i++) {
        if(num1 % i == 0 && num2 % i == 0) {
            scd = i;
            break;
        }
    }

    // Euclidean Algorithm for GCD
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    if(scd == -1)
        printf("No common divisor other than 1\n");
    else
        printf("Smallest Common Divisor: %d\n", scd);

    printf("Greatest Common Divisor (GCD): %d\n", gcd);

    return 0;
}
