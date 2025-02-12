#ifndef GAME_H
#define GAME_H

#include <stdio.h>

// Définition de la structure Supemon
typedef struct {
    char name[50];
    int level;
    int hp;
    int max_hp;
    int attack;
    int defense;
    int evasion;
    int accuracy;
    int speed;
    struct {
        char name[50];
        int power;
    } moves[4]; 
} Supemon;

// Définition de la structure Item
typedef struct {
    char name[50];
    int quantity;
    char effect[100];
    int value;
} Item;

// Définition de la structure Player
typedef struct {
    char name[50];
    int supemon_count;
    int item_count;
    int supcoins;
    Supemon supemons[10]; 
    Item items[10];       
} Player;

// Prototypes des fonctions
void init_player(Player *player);
void list_supemons(Supemon supemons[], int count);
void list_items(Item items[], int count);

#endif // GAME_H
