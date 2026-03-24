#include <stdio.h>

enum Days { 
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

int main() {
    enum Days today = WEDNESDAY;
    
    // This will print "Today is day number: 3"
    printf("Today is day number: %d\n", today);
    
    return 0;
}
