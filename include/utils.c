#include <stdio.h>
#include <stdlib.h>
#include "src/utils.h"

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void init_random_seed() {
    unsigned int seed = (unsigned int)&min + (unsigned int)&max; 
    srand(seed);
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause_console() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void display_title(const char *title) {
    printf("\n=== %s ===\n", title);
}
