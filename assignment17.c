#include <stdio.h>

double factorial(int n) {
    double fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    double x, sum = 0;

    printf("Enter angle in radians: ");
    scanf("%lf", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        double term = 1;

        // calculate x^(2i+1)
        for(int j = 1; j <= (2*i + 1); j++) {
            term *= x;
        }

        term = term / factorial(2*i + 1);

        if(i % 2 == 0)
            sum += term;
        else
            sum -= term;
    }

    printf("sin(x) = %lf", sum);

    return 0;
}
