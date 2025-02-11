#ifndef BATTLE_H
#define BATTLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "src/player.h"
#include "src/supemon.h"

void use_item(Item *item, Supemon *supemon);

void battle(Player *player, Supemon *wild_supemon);

#endif 
