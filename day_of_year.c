/* print a date of the nth day in a given year
 * or the day number of a date */
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* returns the day number for a given date */
int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (1 > day || day > daytab[leap][day] || month > 12 || month < 1) {
        return 0;
    }
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* puts the date of nth day in the corresponding variables pointed by pday and pmonth pointers */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
int main (void) {
    int m, d;
    month_day(1988, 60, &m, &d);
    printf("%d %d %d\n", m, d, day_of_year(1988, m, d));

    return 0;
}
