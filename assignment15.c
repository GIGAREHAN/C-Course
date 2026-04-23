#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    srand(time(0));  // seed for random numbers

    for(i = 0; i < n; i++) {
        printf("%d\n", rand());
    }

    return 0;
}
