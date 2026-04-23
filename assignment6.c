#include <stdio.h>
void main() {

    // number and result variable
    int n, factorial;
    printf("Enter the number: ");
    scanf("%d", &n); //Take in number from user
    factorial = 1; 


    while (n > 0) //Looping multiplication until n = 1
    {
        factorial = factorial * n;
        n = n - 1;
    };
    printf("Factorial is: %d", factorial);
}
