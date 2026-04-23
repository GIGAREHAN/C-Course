#include <stdio.h>

struct student {
    char name[20];
    int r_no;
    float m1, m2, result;

};

int main() {
    int i;

    struct student s[10];
    printf("Enter student details");

    for (i = 0; i < 3; i++) {
        printf("\nStudent %d\n", i + 1);
        
        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter Roll no: ");
        scanf("%d", &s[i].r_no);

        printf("Enter marks (m1 and m2): ");
        scanf("%f %f", &s[i].m1, &s[i].m2);

        s[i].result = (s[i].m1 + s[i].m2)/2;

    }

    printf("\n------ Student Details ---------\n");

    for(i = 0; i < 3; i++) {
        printf("Name: %s | Roll no: %d | Marks: %.2f, %.2f | Result: %.2f\n", s[i].name, s[i].r_no, s[i].m1, s[i].m2, s[i].result);
    }
    
}
