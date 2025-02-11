#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "src/supemon.h"

void init_move(Move *move, const char *name, int power, EffectType effect) {
    strcpy(move->name, name);
    move->power = power;
    move->effect = effect;
}

void init_supemon(Supemon *supemon, const char *name, int hp, int attack, int defense, int evasion, int accuracy, int speed, Move moves[], int move_count) {
    strcpy(supemon->name, name);
    supemon->level = 1;
    supemon->experience = 0;
    supemon->hp = hp;
    supemon->attack = attack;
    supemon->defense = defense;
    supemon->evasion = evasion;
    supemon->accuracy = accuracy;
    supemon->speed = speed;
    
    for (int i = 0; i < move_count; i++) {
        supemon->moves[i] = moves[i];
    }
}

void level_up(Supemon *supemon) {
    supemon->level++;
    
    supemon->hp += round((supemon->hp * 0.3) + ((rand() % 2) ? 0.5 : 0));
    supemon->attack += round((supemon->attack * 0.3) + ((rand() % 2) ? 0.5 : 0));
    supemon->defense += round((supemon->defense * 0.3) + ((rand() % 2) ? 0.5 : 0));
    supemon->evasion += round((supemon->evasion * 0.3) + ((rand() % 2) ? 0.5 : 0));
    supemon->accuracy += round((supemon->accuracy * 0.3) + ((rand() % 2) ? 0.5 : 0));
    supemon->speed += round((supemon->speed * 0.3) + ((rand() % 2) ? 0.5 : 0));
}

void gain_experience(Supemon *supemon, int exp) {
    supemon->experience += exp;
    int required_exp = 500 + (supemon->level - 1) * 1000;
    while (supemon->experience >= required_exp) {
        supemon->experience -= required_exp;
        level_up(supemon);
        required_exp = 500 + (supemon->level - 1) * 1000;
    }
}

void init_all_moves(Move *all_moves) {
    init_move(&all_moves[0], "Scratch", 3, DAMAGE);
    init_move(&all_moves[1], "Growl", 1, BOOST_ATTACK);
    init_move(&all_moves[2], "Pound", 2, DAMAGE);
    init_move(&all_moves[3], "Foliage", 1, BOOST_EVASION);
    init_move(&all_moves[4], "Shell", 1, BOOST_DEFENSE);
}

void init_all_supemons(Supemon *supemons, Move *all_moves) {
    Move supmander_moves[] = {all_moves[0], all_moves[1]};
    init_supemon(&supemons[0], "Supmander", 10, 1, 1, 1, 2, 1, supmander_moves, 2);
    
    Move supasaur_moves[] = {all_moves[2], all_moves[3]};
    init_supemon(&supemons[1], "Supasaur", 9, 1, 1, 3, 2, 2, supasaur_moves, 2);
    
    Move supirtle_moves[] = {all_moves[2], all_moves[4]};
    init_supemon(&supemons[2], "Supirtle", 11, 1, 2, 2, 1, 2, supirtle_moves, 2);
}
