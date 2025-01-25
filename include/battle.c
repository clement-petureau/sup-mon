#include <stdio.h>
#include "src/battle.h"

void battle(Player *player, Supemon *wild_supemon) {
    printf("Wild %s appeared! Prepare to battle!\n", wild_supemon->name);
    int player_supemon_idx = 0;

    while (wild_supemon->hp > 0) {
        Supemon *player_supemon = &player->supemons[player_supemon_idx];
        printf("Your Supémon: %s (HP: %d/%d)\n", player_supemon->name, player_supemon->hp, player_supemon->max_hp);
        printf("1. Attack\n2. Switch Supémon\n3. Run\nChoose your action: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int damage = (player_supemon->attack * 3) / wild_supemon->defense;
            wild_supemon->hp -= damage;
            printf("%s attacked %s for %d damage!\n", player_supemon->name, wild_supemon->name, damage);

            if (wild_supemon->hp <= 0) {
                printf("You defeated %s!\n", wild_supemon->name);
                int reward = 100 + rand() % 401;
                player->supcoins += reward;
                printf("You earned %d Supcoins!\n", reward);
                return;
            }

            damage = (wild_supemon->attack * 3) / player_supemon->defense;
            player_supemon->hp -= damage;
            printf("%s attacked %s for %d damage!\n", wild_supemon->name, player_supemon->name, damage);

            if (player_supemon->hp <= 0) {
                printf("Your %s fainted!\n", player_supemon->name);
                return;
            }
        } else if (choice == 2) {
            printf("Switching Supémon...\n");
            list_supemons(player->supemons, player->supemon_count);
            printf("Choose a Supémon: ");
            scanf("%d", &player_supemon_idx);
            player_supemon_idx--; // Convert to array index
        } else if (choice == 3) {
            printf("You ran away!\n");
            return;
        }
    }
}
