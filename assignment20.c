#include <stdio.h>

// Function without pointers (Call by Value)
void swapValue(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;

    printf("\nAfter swapping without pointers:\n");
    printf("a = %d b = %d\n", a, b);
}

// Function with pointers (Call by Reference)
void swapPointer(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Call by value
    swapValue(a, b);

    // Call by reference
    swapPointer(&a, &b);

    printf("\nAfter swapping with pointers:\n");
    printf("x = %d y = %d\n", a, b);

    return 0;
}
