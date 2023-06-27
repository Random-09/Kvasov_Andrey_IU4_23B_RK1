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
    game_data->remaining_len = curr_text_len;
    game_data->curr_text_len = curr_text_len;
    game_data->curr_text = curr_text;
    game_data->screen_len = height * width;
    game_data->width = width;
    game_data->height = height;
    return game_data;
}

void print_part_of_text(GameData_t *game_data) {
    clear();
    move(0, 0);
    int end_pos;
    if (game_data->remaining_len < game_data->screen_len)
        end_pos = game_data->text_pos + game_data->remaining_len;
    else
        end_pos = game_data->text_pos + game_data->screen_len;
    for (int i = game_data->text_pos; i <= end_pos; i++)
        printw("%c", game_data->curr_text[i]);
    refresh();
    game_data->text_pos = end_pos;
    game_data->remaining_len -= game_data->screen_len;
}