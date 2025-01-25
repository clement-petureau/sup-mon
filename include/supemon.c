#include <string.h>
#include "src/supemon.h"

void init_supemon(Supemon *supemon, char *name, int hp, int attack, int defense, int evasion, int accuracy, int speed) {
    strcpy(supemon->name, name);
    supemon->level = 1;
    supemon->experience = 0;
    supemon->hp = supemon->max_hp = hp;
    supemon->attack = supemon->base_attack = attack;
    supemon->defense = supemon->base_defense = defense;
    supemon->evasion = supemon->base_evasion = evasion;
    supemon->accuracy = supemon->base_accuracy = accuracy;
    supemon->speed = speed;
}
