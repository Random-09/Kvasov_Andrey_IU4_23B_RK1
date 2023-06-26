#ifndef KVASOV_ANDREY_IU4_23B_RK1_GAME_H
#define KVASOV_ANDREY_IU4_23B_RK1_GAME_H

#include <string.h>
#include <stdbool.h>

#define TEXT_1 "Some text to print on screen large enough to test all the features until my fantasy comes up with " \
"something more original and suitable for a simple level of the game. OKAY that text wasn't large enough. So if you " \
"thought that would stop me... you underestimated me! I will continue typing nonsense until my needs are fulfilled!"

typedef struct Statistics {
    int correct_symb_num;
    int incorrect_symb_num;
    int total_symb_num;
    float average_symb_speed;
    float average_word_speed;
} Statistics_t;

void print_statistics(Statistics_t statistics);

void check_args(char *difficulty, int time_limit, int error_limit);

void print_help();

#endif
