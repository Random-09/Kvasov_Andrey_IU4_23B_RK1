#include "../include/game.h"


void check_args(char *difficulty, int time_limit, int error_limit) {
    bool show_help_msg = false;
    if (strcmp(difficulty, "easy") > 0 || strcmp(difficulty, "medium") > 0 ||
        strcmp(difficulty, "hard") > 0) {
        printw("Difficulty argument does not match \"easy\" \"medium\" or \"hard\" options.\n");
        show_help_msg = true;
    }
    if (time_limit == 0) {
        printw("Time limit argument is not a digit or is equal to zero.\n");
        show_help_msg = true;
    }
    if (error_limit == 0) {
        printw("Error limit argument is not a digit or is equal to zero.\n");
        show_help_msg = true;
    }
    if (show_help_msg)
        printw("\nUsage:\n./RK1.elf <arguments>\n\nArguments:\n-d\t\tChoose difficulty (easy, medium or hard)\n"
               "-t\t\tTime limit in seconds\n-e\t\tError limit\n");
}
