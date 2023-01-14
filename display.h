#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "ncurses.h"
#include <stdlib.h>

int open_display(void);
void display_time(int hours, int munites, int seconds);
void display_colons(void);
void display_hours(int hours);
void display_minutes(int minutes);
void display_seconds(int seconds);
void close_display(void);
