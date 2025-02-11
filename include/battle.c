#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/battle.h"
#include "src/player.h"

void use_item(Item *item, Supemon *supemon) {
    if (strcmp(item->name, "Potion") == 0) {
        supemon->hp += 5;
        if (supemon->hp > supemon->max_hp) supemon->hp = supemon->max_hp;
        printf("%s used a Potion! +5 HP!\n", supemon->name);
    } else if (strcmp(item->name, "Super Potion") == 0) {
        supemon->hp += 10;
        if (supemon->hp > supemon->max_hp) supemon->hp = supemon->max_hp;
        printf("%s used a Super Potion! +10 HP!\n", supemon->name);
    } else if (strcmp(item->name, "Rare Candy") == 0) {
        supemon->level++;
        supemon->attack = (int)(supemon->attack * 1.3 + 0.5);
        supemon->defense = (int)(supemon->defense * 1.3 + 0.5);
        supemon->evasion = (int)(supemon->evasion * 1.3 + 0.5);
        supemon->accuracy = (int)(supemon->accuracy * 1.3 + 0.5);
        supemon->speed = (int)(supemon->speed * 1.3 + 0.5);
        supemon->max_hp = (int)(supemon->max_hp * 1.3 + 0.5);
        printf("%s used a Rare Candy! Level up to %d!\n", supemon->name, supemon->level);
    }
}

void battle(Player *player, Supemon *wild_supemon) {
    printf("Wild %s appeared! Prepare to battle!\n", wild_supemon->name);
    int player_supemon_idx = 0;
    Supemon *player_supemon = &player->supemons[player_supemon_idx];

    int player_turn = player_supemon->speed > wild_supemon->speed || (player_supemon->speed == wild_supemon->speed && rand() % 2 == 0);

    while (player_supemon->hp > 0 && wild_supemon->hp > 0) {
        printf("Your Supémon: %s (HP: %d/%d)\n", player_supemon->name, player_supemon->hp, player_supemon->max_hp);
        printf("Enemy Supémon: %s (HP: %d/%d)\n", wild_supemon->name, wild_supemon->hp, wild_supemon->max_hp);
        
        if (player_turn) {
            printf("1. Attack\n2. Switch Supémon\n3. Use Item\n4. Run\n5. Capture\nChoose your action: ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                printf("Choose a move:\n");
                for (int i = 0; i < MAX_MOVES; i++) {
                    if (player_supemon->moves[i].name[0] != '\0') {
                        printf("%d. %s\n", i + 1, player_supemon->moves[i].name);
                    }
                }
                int move_choice;
                scanf("%d", &move_choice);
                move_choice--;

                Move selected_move = player_supemon->moves[move_choice];
                float hit_chance = (float)player_supemon->accuracy / (player_supemon->accuracy + wild_supemon->evasion) + 0.1;
                if ((rand() % 100) < hit_chance * 100) {
                    int damage = (player_supemon->attack * selected_move.power) / wild_supemon->defense;
                    if ((player_supemon->attack * selected_move.power) % wild_supemon->defense != 0) {
                        damage += (rand() % 2);
                    }
                    wild_supemon->hp -= damage;
                    printf("%s used %s and dealt %d damage!\n", player_supemon->name, selected_move.name, damage);
                } else {
                    printf("%s missed the attack!\n", player_supemon->name);
                }
            } else if (choice == 2) {
                printf("Switching Supémon...\n");
                list_supemons(player->supemons, player->supemon_count);
                printf("Choose a Supémon: ");
                scanf("%d", &player_supemon_idx);
                player_supemon_idx--; 
            } else if (choice == 3) {
                if (player->item_count == 0) {
                    printf("You have no items!\n");
                } else {
                    printf("Choose an item:\n");
                    for (int i = 0; i < player->item_count; i++) {
                        printf("%d. %s (x%d)\n", i + 1, player->items[i].name, player->items[i].quantity);
                    }
                    int item_choice;
                    scanf("%d", &item_choice);
                    item_choice--;

                    if (item_choice >= 0 && item_choice < player->item_count && player->items[item_choice].quantity > 0) {
                        use_item(&player->items[item_choice], player_supemon);
                        player->items[item_choice].quantity--;
                    } else {
                        printf("Invalid choice or out of stock!\n");
                    }
                }
            } else if (choice == 4) {
                float escape_chance = (float)player_supemon->speed / (player_supemon->speed + wild_supemon->speed);
                if ((rand() % 100) < escape_chance * 100) {
                    printf("You successfully ran away!\n");
                    return;
                } else {
                    printf("You failed to run away!\n");
                }
            } else if (choice == 5) {
                float capture_chance = (float)(wild_supemon->max_hp - wild_supemon->hp) / wild_supemon->max_hp - 0.5;
                if ((rand() % 100) < capture_chance * 100) {
                    printf("You captured %s!\n", wild_supemon->name);
                    return;
                } else {
                    printf("Capture failed!\n");
                }
            }
        } else {
            // Tour de l'ennemi
            int move_index = rand() % MAX_MOVES;
            Move enemy_move = wild_supemon->moves[move_index];
            float hit_chance = (float)wild_supemon->accuracy / (wild_supemon->accuracy + player_supemon->evasion) + 0.1;
            if ((rand() % 100) < hit_chance * 100) {
                int damage = (wild_supemon->attack * enemy_move.power) / player_supemon->defense;
                if ((wild_supemon->attack * enemy_move.power) % player_supemon->defense != 0) {
                    damage += (rand() % 2);
                }
                player_supemon->hp -= damage;
                printf("%s used %s and dealt %d damage!\n", wild_supemon->name, enemy_move.name, damage);
            } else {
                printf("%s missed the attack!\n", wild_supemon->name);
            }
        }
        player_turn = !player_turn;
    }
    
if (player_supemon->hp <= 0) {
        printf("Your %s fainted!\n", player_supemon->name);
    } else {
        printf("You defeated %s!\n", wild_supemon->name);
        int reward = 100 + rand() % 401;
        player->supcoins += reward;
        int exp_gain = (100 + rand() % 401) * wild_supemon->level;
        player_supemon->experience += exp_gain;
        printf("You earned %d Supcoins and %d experience!\n", reward, exp_gain);
    }
}
