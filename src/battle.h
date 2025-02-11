#ifndef BATTLE_H
#define BATTLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "src/player.h"
#include "src/supemon.h"

// Prototypes des fonctions

// Fonction pour utiliser un objet sur un Supémon
void use_item(Item *item, Supemon *supemon);

// Fonction pour gérer un combat entre le joueur et un Supémon sauvage
void battle(Player *player, Supemon *wild_supemon);

#endif // BATTLE_H
