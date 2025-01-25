#include <stdio.h>
#include "src/shop.h"

void shop(Player *player) {
    printf("Welcome to the shop! You have %d Supcoins.\n", player->supcoins);
    printf("1. Potion (+5 HP) - 100 Supcoins\n2. Super Potion (+10 HP) - 300 Supcoins\n3. Rare Candy (Level Up) - 700 Supcoins\n");
    printf("Choose an item to buy or 0 to exit: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 0) return;
    int cost = (choice == 1) ? 100 : (choice == 2) ? 300 : 700;
    if (player->supcoins >= cost) {
        player->supcoins -= cost;
        printf("Item purchased successfully! Remaining Supcoins: %d\n", player->supcoins);
    } else {
        printf("Not enough Supcoins!\n");
    }
}
