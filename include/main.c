#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/player.h"
#include "src/supemon.h"
#include "src/battle.h"
#include "src/shop.h"
#include "src/center.h"

int main() {
    srand(time(NULL));

    Player player;
    Supemon supmander, supasaur, supirtle;
    init_supemon(&supmander, "Supmander", 10, 1, 1, 1, 2, 1);
    init_supemon(&supasaur, "Supasaur", 9, 1, 1, 3, 2, 2);
    init_supemon(&supirtle, "Supirtle", 11, 1, 2, 2, 1, 2);

    init_player(&player);
    player.supemons[player.supemon_count++] = supmander;

    while (1) {
        printf("\n1. Into the Wild\n2. Supémon Center\n3. Shop\n4. Exit\nChoose an action: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            Supemon wild_supemon;
            init_supemon(&wild_supemon, "Wildmon", 8, 1, 1, 1, 1, 1);
            battle(&player, &wild_supemon);
        } else if (choice == 2) {
            supemon_center(&player);
        } else if (choice == 3) {
            shop(&player);
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}
