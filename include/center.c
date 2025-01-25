#include <stdio.h>
#include "src/center.h"

void supemon_center(Player *player) {
    printf("\nWelcome to the Supémon Center!\n");
    printf("Here, we heal all your Supémons for free.\n");

    if (player->supemon_count == 0) {
        printf("You don't have any Supémon to heal!\n");
        return;
    }

    for (int i = 0; i < player->supemon_count; i++) {
        player->supemons[i].hp = player->supemons[i].max_hp;
    }

    printf("All your Supémons have been fully healed!\n");
    printf("Here's the status of your team:\n");
    list_supemons(player->supemons, player->supemon_count);
}
