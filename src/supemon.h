#ifndef SUPEMON_H
#define SUPEMON_H

typedef struct {
    char name[50];
    int level;
    int experience;
    int hp, max_hp;
    int attack, base_attack;
    int defense, base_defense;
    int evasion, base_evasion;
    int accuracy, base_accuracy;
    int speed;
} Supemon;

void init_supemon(Supemon *supemon, char *name, int hp, int attack, int defense, int evasion, int accuracy, int speed);

#endif
