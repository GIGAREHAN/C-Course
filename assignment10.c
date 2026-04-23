#include <stdio.h>
#include <math.h>
unsigned long long calculateFactorial(int num1);
void main(){

    int num1, num2, choice;
    printf("Enter two numbers: \n");
    printf("Enter number one: ");
    scanf("%d", &num1);
    printf("Enter number two: ");
    scanf("%d", &num2);

    printf("Select choice: \n 1.Addition \n 2.Substraction \n 3.Multiplication \n 4.Division \n 5.Power \n 6.Factorial\n");
    scanf("%d", &choice);
    switch(choice) {

        case 1:
            printf("Addition is: %d", num1+num2);
            break;
        
        case 2:
            printf("Substraction is: %d", num1-num2);
            break;
        
        case 3:
            printf("Multiplication is: %d", num1*num2);
            break;
        
        case 4:
            if (num2 != 0){
                printf("Division is: %.2f", (double)num1 / num2);
                break;
            } else {
                printf("Not possible Zero division error");
                break;
            };

        case 5:
            float result = pow(num1, num2);
            printf("%d raised to %d is: %.2f", num1, num2, result);
            break;
        
        case 6:
            if (num1 < 0) {
                    printf("Error: Factorial of a negative number doesn't exist.\n");
            } else {
                    printf("Result: %llu\n", calculateFactorial(num1));
            }
            break;
    };
}

unsigned long long calculateFactorial(int num1) {
    if (num1 < 0) {return 0;};
    if (num1 == 1) {return 1;};


    unsigned long long fact = 1;
    for (int i = 1; i <= num1; i++) {
        fact = fact * i;
    }
    return fact;
}
