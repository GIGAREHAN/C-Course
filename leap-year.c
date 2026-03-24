//Leap Year code:
#include <stdio.h>
int checkYear(int x);
int main()
{
    int a, ans;
    printf("Enter Year: ");
    scanf("%d", &a);

    ans = checkYear(a);
    if (ans == 1) {
        printf("It is a leap year");
    }
    else {
        printf("Not a leap year");
    }
    getch();

}

int checkYear(int x) {
    if (x % 4 == 0) {

        if (x % 100 == 0) {
            if (x % 400 == 0) {
                return(1);
            }
            return(0);
        }
        return(1);
    }
}
