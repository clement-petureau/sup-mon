#include <stdio.h>
#include <src/string.h>
#include "src/player.h"

void init_player(Player *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
    player->supemon_count = 0;
    player->item_count = 0;
    player->supcoins = 500;
}

void list_supemons(Supemon supemons[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s (HP: %d/%d, Level: %d)\n", i + 1, supemons[i].name, supemons[i].hp, supemons[i].max_hp, supemons[i].level);
    }
}
