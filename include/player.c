#include <stdio.h>
#include <src/string.h>
#include "src/player.h"

#define MAX_MOVES 4

void init_player(Player *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
    player->supemon_count = 0;
    player->item_count = 0;
    player->supcoins = 500;
}

void list_supemons(Supemon supemons[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Level: %d, HP: %d/%d, Attack: %d, Defense: %d, Evasion: %d, Accuracy: %d, Speed: %d)\n", 
               i + 1, supemons[i].name, supemons[i].level, supemons[i].hp, supemons[i].max_hp, 
               supemons[i].attack, supemons[i].defense, supemons[i].evasion, supemons[i].accuracy, supemons[i].speed);
        printf("   Moves: ");
        for (int j = 0; j < MAX_MOVES; j++) {
            if (supemons[i].moves[j].name[0] != '\0') {
                printf("%s (%d dmg) ", supemons[i].moves[j].name, supemons[i].moves[j].power);
            }
        }
        printf("\n");
    }
}

void list_items(Item items[], int count) {
    printf("Your Items:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (x%d) - Effect: %s\n", i + 1, items[i].name, items[i].quantity, items[i].effect, items[i].value);
    }
}
