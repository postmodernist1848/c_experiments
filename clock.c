#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main (void) {
int timer;
while (1){
    fflush(stdout);
    timer = time(NULL) % (24 * 60 * 60);
    printf(" |  %.2d:%.2d:%.2d  |\r", timer / (60 * 60) + 3, timer / (60) % 60, timer % 60);
    delay(1000);

}
return 0;
}