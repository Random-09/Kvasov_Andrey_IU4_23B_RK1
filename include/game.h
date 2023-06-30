#ifndef KVASOV_ANDREY_IU4_23B_RK1_GAME_H
#define KVASOV_ANDREY_IU4_23B_RK1_GAME_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#define EASY_TEXT "Just some easy small text"

#define MEDIUM_TEXT "A little bit larger text this time to check your abilities in typing even further"

#define HARD_TEXT "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor" \
" incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation" \
" ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit" \
" in voluptate velit esse cillum dolore eu fugiat nulla pariatur"

#define EASY_TEXT_LEN 25

#define MEDIUM_TEXT_LEN 81

#define HARD_TEXT_LEN 333

#define CORRECT_HIGHLIGHT 1

#define INCORRECT_HIGHLIGHT 2

typedef struct GameData {
    int text_pos;
    int cursor_pos;
    int screen_len;
    char *curr_text;
    int curr_text_len;
    int width;
    int height;
} GameData_t;

typedef struct Statistics {
    int correct_symb_num;
    int incorrect_symb_num;
    int total_symb_num;
    int total_words;
} Statistics_t;

GameData_t *init_game_data(char *difficulty);

void print_statistics(Statistics_t *statistics, double cpm, double wpm);

#endif
