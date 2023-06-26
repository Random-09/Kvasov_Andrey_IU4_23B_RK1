#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <getopt.h>
#include "include/game.h"

int main(int argc, char **argv) {
    int opt;
    int time_limit;
    int error_limit;
    char *difficulty;
    while ((opt = getopt(argc, argv, "d:t:e:")) != -1) {
        switch (opt) {
            case 'd':
                difficulty = optarg;
                break;
            case 't':
                time_limit = strtol(optarg, NULL, 10);
                break;
            case 'e':
                error_limit = strtol(optarg, NULL, 10);
                break;
            default:
                printw("default");
                exit(EXIT_FAILURE);
        }
    }
    initscr();
    printw("%s %d %d\n", difficulty, time_limit, error_limit);
    check_args(difficulty, time_limit, error_limit);
    refresh();
    getch();
    endwin();
    return 0;
}
