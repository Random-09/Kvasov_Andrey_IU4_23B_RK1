#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>
#include "include/game.h"
#include "include/args_check.h"

int main(int argc, char **argv) {
    int opt;
    int time_limit;
    int error_limit;
    char *difficulty;
    while ((opt = getopt(argc, argv, "d:t:e:")) != -1) {            // <---- АРГУМЕНТЫ (LONG_OPT)
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
    check_args(difficulty, time_limit, error_limit);
    initscr();
    GameData_t *game_data = init_game_data(difficulty);
    bool time_limit_reached = false;
    bool error_limit_reached = false;
    start_color();
    init_pair(CORRECT_HIGHLIGHT, COLOR_GREEN, COLOR_BLACK);
    init_pair(INCORRECT_HIGHLIGHT, COLOR_RED, COLOR_BLACK);
    while (game_data->cursor_pos != game_data->curr_text_len || !time_limit_reached || !error_limit_reached) {
        if (game_data->cursor_pos == game_data->text_pos || game_data->cursor_pos == 1) {
            print_part_of_text(game_data);
        }
        refresh();
        int symb = getch();
        if (symb == game_data->curr_text[game_data->cursor_pos]) {
            attron(COLOR_PAIR(CORRECT_HIGHLIGHT));
            //move();
            printw("%c", symb);
//            attroff(COLOR_PAIR(CORRECT_HIGHLIGHT));
        } else {
            attron(COLOR_PAIR(INCORRECT_HIGHLIGHT));
            printw("%c", symb);
//            attroff(COLOR_PAIR(INCORRECT_HIGHLIGHT));
            game_data->cursor_pos++;
            game_data->remaining_len--;
            int new_y = game_data->cursor_pos / game_data->width;
            int new_x = game_data->cursor_pos % game_data->width;
            move(new_y, new_x);
        }
    }
    getch();
    endwin();
    return 0;
}