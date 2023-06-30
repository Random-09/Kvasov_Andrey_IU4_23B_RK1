#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "include/game.h"
#include "include/args_check.h"

#define BILLION 1000000000.0

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
    initscr();
    GameData_t *game_data = init_game_data(difficulty);
    Statistics_t *statistics = malloc(sizeof(Statistics_t));
    bool time_limit_reached = false;
    bool error_limit_reached = false;
    start_color();
    init_pair(CORRECT_HIGHLIGHT, COLOR_GREEN, COLOR_BLACK);
    init_pair(INCORRECT_HIGHLIGHT, COLOR_RED, COLOR_BLACK);
    printw("%s", game_data->curr_text);
    move(0, 0);
    refresh();
    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);
    double time = 0;
    while (game_data->cursor_pos != game_data->curr_text_len) {
        clock_gettime(CLOCK_REALTIME, &end);

        time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

        if (time >= time_limit) {
            break;
        }
        int symb = getch();
        if (symb == game_data->curr_text[game_data->cursor_pos]) {
            attron(COLOR_PAIR(CORRECT_HIGHLIGHT));
            addch(game_data->curr_text[game_data->cursor_pos]);
            statistics->correct_symb_num++;
        } else {
            attron(COLOR_PAIR(INCORRECT_HIGHLIGHT));
            addch(game_data->curr_text[game_data->cursor_pos]);
            statistics->incorrect_symb_num++;
        }
        if (game_data->curr_text[game_data->cursor_pos] == ' ' ||
            game_data->curr_text[game_data->cursor_pos] == '\n')
            statistics->total_words++;
        refresh();
        if (statistics->incorrect_symb_num >= error_limit) {
            break;
        }
        game_data->cursor_pos++;
        statistics->total_symb_num++;
        move(0, game_data->cursor_pos);
    }
    attroff(COLOR_PAIR(INCORRECT_HIGHLIGHT));
    attroff(COLOR_PAIR(CORRECT_HIGHLIGHT));
    double characters_per_minute = game_data->curr_text_len / (time/60);
    double words_per_minute = statistics->total_words / (time/60);
    print_statistics(statistics, characters_per_minute, words_per_minute);
    getch();
    endwin();
    free(game_data);
    free(statistics);
    return 0;
}