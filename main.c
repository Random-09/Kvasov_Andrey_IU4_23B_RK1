#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <getopt.h>
#include <string.h>
#include "include/game.h"
#include "include/args_check.h"

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
    check_args(difficulty, time_limit, error_limit);
    char *curr_text;
    int curr_text_len;
    if (strcmp(difficulty, "easy") == 0) {
        curr_text = EASY_TEXT;
        curr_text_len = EASY_TEXT_LEN;
    }
    if (strcmp(difficulty, "medium") == 0) {
        curr_text = MEDIUM_TEXT;
        curr_text_len = MEDIUM_TEXT_LEN;
    }
    if (strcmp(difficulty, "hard") == 0) {
        curr_text = HARD_TEXT;
        curr_text_len = HARD_TEXT_LEN;
    }
    initscr();
    int height, width;
    getmaxyx(stdscr, height, width);
    int total_space = height * width;
    GameData_t *game_data;
    game_data = (GameData_t *) malloc(sizeof(GameData_t));
    game_data->text_pos = 0;
    game_data->cursor_pos = 0;
    game_data->remaining_len = curr_text_len;
    game_data->curr_text_len = curr_text_len;
    game_data->curr_text = curr_text;
    game_data->total_space = total_space;
    print_part_of_text(game_data);
    printw("%d", game_data->text_pos);
    refresh();
    getch();
    endwin();
    return 0;
}
