#include <stdio.h>
#include <math.h>

float squareRoot(int n);
int squareNum(int n);
int cubeNum(int n);
int isPrime(int n);
unsigned long long calculateFactorial(int n);
void primeFactors(int n);

int main() {
    int num, result;
    int choice;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the choice: \n1.Square root \n2.Sqaure \n3.Cube \n4.Is it prime \n5.Factorial \n6.Prime Factors");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        if (num < 0) {
        printf("\nCannot find square root of negative number");
        } else {
            printf("\nSquare root of %d is: %.3f", num, squareRoot(num));
        }
        break;

    case 2:
        printf("\nSquare of %d is: %d", num, squareNum(num));
        break;
    case 3:
        printf("\nCube of %d is %d", num, cubeNum(num));
        break;
    case 4:
        if (isPrime(num) == 1) {
            printf("\n%d is prime", num);
        } else {
            printf("\n%d is not prime", num);
        };
        break;
    
    case 5:
        printf("Factorial of %d is %llu", num, calculateFactorial(num));
        break;
    case 6:
        printf("Prime Factors of ");
        primeFactors(num);
        break;
        
    default:
        printf("Invalid Choice");
        break;
    };
}

float squareRoot(int n) {
    return sqrt(n);
};

int squareNum(int n) {
    return n * n;
};

int cubeNum(int n) {
    return n * n * n;
};

int isPrime(int n) {

};

unsigned long long calculateFactorial(int n) {
    if (n == 0) {return 0;};
    if (n == 1) {return 1;};

    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    };
    return fact;
};

void primeFactors(int n){

};
