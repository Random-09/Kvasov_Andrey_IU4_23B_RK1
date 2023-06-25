#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "include/game.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        puts("Wrong number of args!");
        exit(EXIT_FAILURE);
    }
    char *difficulty = argv[1];
    int time_limit = strtol(argv[2], NULL, 10);
    int error_limit = strtol(argv[3], NULL, 10);



    initscr();
    printw("%s", TEXT_1);
    refresh();
    getch();
    endwin();
    return ;
}
