#include <stddef.h>
#include "display.h"
#include <unistd.h>
#include <stdio.h>

int main(void){
    open_display();
    display_colons();
     char input[0];
    int hours;
    int minutes;
    int seconds;
    int items = 3;
    while (items == 3){
        items = scanf("%02d:%02d:%02d", &hours, &minutes, &seconds);
        display_time(hours, minutes, seconds);
    }
    sleep(3);
    close_display();
    return 1;
}


