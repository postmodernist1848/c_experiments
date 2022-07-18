/* I often forget how old I am, so I wrote this program
that shows exactly how much time has passed since my birth */

#include <stdio.h>
#include <time.h>

#define BIRTHDAY 1103673600 //Hardcoded birth date: 22.12.2004

int main(void) {
    time_t curr_time;
    if ((curr_time = time(NULL)) != -1) {
        time_t time_since_birth = curr_time - BIRTHDAY;
        struct tm *ptm = localtime(&time_since_birth);
        
        if (ptm == NULL) {
            
            puts("The localtime() function failed");
            return 1;
        }
        
        printf("I am %d years, %d months, %d days, %d hours, %d minutes and %d seconds old.\n", ptm->tm_year - 70, 
            ptm->tm_mon, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

    }
    else puts("The time() function failed");
return 0;
}