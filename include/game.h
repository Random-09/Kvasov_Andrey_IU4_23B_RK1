#ifndef KVASOV_ANDREY_IU4_23B_RK1_GAME_H
#define KVASOV_ANDREY_IU4_23B_RK1_GAME_H

#define EASY_TEXT "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

#define MEDIUM_TEXT "text 2"

#define HARD_TEXT "text 3"

#define EASY_TEXT_LEN 582

#define MEDIUM_TEXT_LEN 10

#define HARD_TEXT_LEN 10

typedef struct GameData {
    int text_pos;
    int cursor_pos;
    int remaining_len;
    int total_space;
    char *curr_text;
    int curr_text_len;
} GameData_t;

typedef struct Statistics {
    int correct_symb_num;
    int incorrect_symb_num;
    int total_symb_num;
    float average_symb_speed;
    float average_word_speed;
} Statistics_t;

void print_part_of_text(GameData_t *game_data);

#endif
