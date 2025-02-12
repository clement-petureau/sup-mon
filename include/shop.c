#include <stdio.h>
#include <string.h>
#include "src/shop.h"

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    char effect[100];
    int value;
    int cost;
} Item;

void init_items(Item *items) {
    strcpy(items[0].name, "Potion");
    strcpy(items[0].effect, "+5 HP");
    items[0].value = 5;
    items[0].cost = 100;

    strcpy(items[1].name, "Super Potion");
    strcpy(items[1].effect, "+10 HP");
    items[1].value = 10;
    items[1].cost = 300;

    strcpy(items[2].name, "Rare Candy");
    strcpy(items[2].effect, "Level Up");
    items[2].value = 1;
    items[2].cost = 700;
}

void shop(Player *player, Item *items) {
    printf("Welcome to the shop! You have %d Supcoins.\n", player->supcoins);
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%s) - %d Supcoins\n", i + 1, items[i].name, items[i].effect, items[i].cost);
    }
    printf("Choose an item to buy or 0 to exit: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 0) return;
    if (choice >= 1 && choice <= 3) {
        int cost = items[choice - 1].cost;
        if (player->supcoins >= cost) {
            player->supcoins -= cost;
            printf("You purchased a %s! Remaining Supcoins: %d\n", items[choice - 1].name, player->supcoins);
            player->items[player->item_count++] = items[choice - 1];
        } else {
            printf("Not enough Supcoins!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }
}
