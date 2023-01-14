#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "ncurses.h"
#include <stdlib.h>
#include "display.h"
#define BLACK 1
#define WHITE 2
#define RED 3
#define BLUE 4
#define GREEN 5

int open_display(void){
    initscr();
    start_color();
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    return 1;
}
void display_time(int hours, int minutes, int seconds){
    display_hours(hours);
    display_minutes(minutes);
    display_seconds(seconds);
    refresh();
}
void display_colons(void){
    attron(COLOR_PAIR(WHITE));
    for (int x=1; x<5; x+=3){
        for (int y=1; y<5; y+=3){
            mvaddch(x, y, '#');
            mvaddch(x+1, y+1, '#');
            mvaddch(x, y+1, '#');
            mvaddch(x+1, y, '#');
        }
    }
    refresh();
}
void display_column(int value, int col, uint16_t color){
    for (int i=0; i<6; i++){
        if (value%2){
            attron(COLOR_PAIR(color));
            mvaddch(i, col, '#');
        }
        else{
            attron(COLOR_PAIR(BLACK));
            mvaddch(i, col, '#');
        }
        value = value/2;
    }
}
void display_hours(int hours){
    display_column(hours, 0, BLUE);
}
void display_minutes(int minutes){
    display_column(minutes, 3, GREEN);
}
void display_seconds(int seconds){
    display_column(seconds, 6, RED);
}
void close_display(void){
    endwin();
}

