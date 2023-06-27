#ifndef KVASOV_ANDREY_IU4_23B_RK1_GAME_H
#define KVASOV_ANDREY_IU4_23B_RK1_GAME_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#define EASY_TEXT "aaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" \
"bbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc" \
"dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd" \
"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" \
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" \
"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"

#define MEDIUM_TEXT "text 2"

#define HARD_TEXT "text 3"

#define EASY_TEXT_LEN 582

#define MEDIUM_TEXT_LEN 10

#define HARD_TEXT_LEN 10

#define CORRECT_HIGHLIGHT 1

#define INCORRECT_HIGHLIGHT 2

typedef struct GameData {
    int text_pos;
    int cursor_pos;
    int remaining_len;
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
    float average_symb_speed;
    float average_word_speed;
} Statistics_t;

GameData_t *init_game_data(char *difficulty);

void print_part_of_text(GameData_t *game_data);

#endif
