#include <stdio.h>

int main() {
    int a, b, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\n1. ADD\n2. SUB\n3. MUL\n4. DIV\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Result = %d", a + b);
            break;
        case 2:
            printf("Result = %d", a - b);
            break;
        case 3:
            printf("Result = %d", a * b);
            break;
        case 4:
            if (b != 0)
                printf("Result = %d", a / b);
            else
                printf("Division by zero not allowed");
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}
