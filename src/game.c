#include "../include/game.h"

//void print_statistics() {
//    mvprintw();
//}

// void init_game_data() {}

void print_part_of_text(GameData_t *game_data) {
    int end_pos;
    if (game_data->remaining_len < game_data->total_space)
        end_pos = game_data->text_pos + game_data->remaining_len;
    else
        end_pos = game_data->text_pos + game_data->curr_text_len;
    for (int i = game_data->text_pos; i < end_pos; i++)
        printw("%c", game_data->curr_text[0]);
    game_data->text_pos = end_pos;
}