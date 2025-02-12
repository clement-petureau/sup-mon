#ifndef SHOP_H
#define SHOP_H

#include <stdio.h>
#include <string.h>
#include "src/player.h" // Assurez-vous que ce fichier existe pour le type Player

#define MAX_ITEMS 10

// Définition de la structure Item
typedef struct {
    char name[50];
    char effect[100];
    int value;
    int cost;
} Item;

// Prototypes des fonctions
void init_items(Item *items);
void shop(Player *player, Item *items);

#endif // SHOP_H
