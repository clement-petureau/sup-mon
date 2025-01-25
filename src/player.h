#ifndef PLAYER_H
#define PLAYER_H

#include "supemon.h"

#define MAX_NAME_LEN 50
#define MAX_ITEMS 10
#define MAX_SUPEMONS 6

typedef struct {
    char name[MAX_NAME_LEN];
    Supemon supemons[MAX_SUPEMONS];
    int supemon_count;
    int supcoins;
    Item items[MAX_ITEMS];
    int item_count;
} Player;

void init_player(Player *player);
void list_supemons(Supemon supemons[], int count);

#endif
