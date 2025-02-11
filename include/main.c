#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "src/player.h"
#include "src/supemon.h"
#include "src/battle.h"
#include "src/shop.h"
#include "src/center.h"

#define SAVE_FILE "player_save.dat"

void save_player(Player *player) {
    FILE *file = fopen(SAVE_FILE, "wb");
    if (file) {
        fwrite(player, sizeof(Player), 1, file);
        fclose(file);
    }
}

int load_player(Player *player) {
    FILE *file = fopen(SAVE_FILE, "rb");
    if (file) {
        fread(player, sizeof(Player), 1, file);
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    Player player;
    int choice;
    
    printf("1. New Game\n2. Load Game\nChoose an option: ");
    scanf("%d", &choice);
    
    if (choice == 2 && load_player(&player)) {
        printf("Game loaded successfully! Welcome back, %s.\n", player.name);
    } else {
        printf("Enter your name: ");
        scanf("%s", player.name);
        init_player(&player);
        
        printf("Choose your starting Supémon:\n1. Supmander\n2. Supasaur\n3. Supirtle\nChoice: ");
        scanf("%d", &choice);
        
        Supemon starter;
        if (choice == 1) {
            init_supemon(&starter, "Supmander", 0, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1);
            add_move(&starter, "Scratch", rand() % (starter.attack / 2) + (starter.attack / 2) + 1, DAMAGE);
            add_move(&starter, "Growl", 0, BOOST_ATTACK);
        } else if (choice == 2) {
            init_supemon(&starter, "Supasaur", 0, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1);
            add_move(&starter, "Pound", rand() % (starter.attack / 2) + (starter.attack / 2) + 1, DAMAGE);
            add_move(&starter, "Foliage", 0, BOOST_EVASION);
        } else {
            init_supemon(&starter, "Supirtle", 0, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1);
            add_move(&starter, "Pound", rand() % (starter.attack / 2) + (starter.attack / 2) + 1, DAMAGE);
            add_move(&starter, "Shell", 0, BOOST_DEFENSE);
        }
        starter.level = 1;
        player.supemons[player.supemon_count++] = starter;
    }

    while (1) {
        printf("\n1. Into the Wild\n2. Supémon Center\n3. Shop\n4. Save and Exit\n5. Exit Without Saving\nChoose an action: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Supemon wild_supemon;
            init_supemon(&wild_supemon, "WildSupemon", 10, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1);
            add_move(&wild_supemon, "Bite", rand() % (wild_supemon.attack / 2) + (wild_supemon.attack / 2) + 1, DAMAGE);
            add_move(&wild_supemon, "Roar", 0, BOOST_ATTACK);
            
            int player_supemon_level = player.supemons[0].level;
            wild_supemon.level = player_supemon_level;
            wild_supemon.hp = (wild_supemon.hp * player_supemon_level) / 1;
            wild_supemon.attack = (wild_supemon.attack * player_supemon_level) / 1;
            wild_supemon.defense = (wild_supemon.defense * player_supemon_level) / 1;
            wild_supemon.evasion = (wild_supemon.evasion * player_supemon_level) / 1;
            wild_supemon.accuracy = (wild_supemon.accuracy * player_supemon_level) / 1;
            wild_supemon.speed = (wild_supemon.speed * player_supemon_level) / 1;
            
            printf("A wild %s appeared! (Level %d)\n", wild_supemon.name, wild_supemon.level);
            battle(&player, &wild_supemon);
        } else if (choice == 2) {
            supemon_center(&player);
        } else if (choice == 3) {
            shop(&player);
        } else if (choice == 4) {
            save_player(&player);
            printf("Game saved. Goodbye!\n");
            break;
        } else if (choice == 5) {
            printf("Exiting without saving. Goodbye!\n");
            break;
        }
    }

    return 0;
}
