#include "../include/game.h"

GameData_t *init_game_data(char *difficulty) {
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
    int height, width;
    getmaxyx(stdscr, height, width);
    GameData_t *game_data;
    game_data = (GameData_t *) malloc(sizeof(GameData_t));
    game_data->text_pos = 1;
    game_data->cursor_pos = 0;
    game_data->curr_text_len = curr_text_len;
    game_data->curr_text = curr_text;
    game_data->screen_len = height * width;
    game_data->width = width;
    game_data->height = height;
    return game_data;
}

void print_statistics(Statistics_t *statistics, double cpm, double wpm) {
    clear();
    move(0, 0);
    printw("Correct symbols: %d\nIncorrect symbols: %d\nTotal symbols: %d\nCharacters per minute: %f\n"
           "Words per minute: %f", statistics->correct_symb_num, statistics->incorrect_symb_num,
           statistics->total_symb_num, cpm, wpm);
}