#ifndef SUPEMON_H
#define SUPEMON_H

#define MAX_MOVES 4

typedef enum {
    DAMAGE,
    BOOST_ATTACK,
    BOOST_DEFENSE,
    BOOST_EVASION
} EffectType;

typedef struct {
    char name[50];
    int power;
    EffectType effect;
} Move;

typedef struct {
    char name[50];
    int level;
    int experience;
    int hp, max_hp;
    int attack;
    int defense;
    int evasion;
    int accuracy;
    int speed;
    Move moves[MAX_MOVES];
} Supemon;

void init_move(Move *move, const char *name, int power, EffectType effect);
void init_supemon(Supemon *supemon, const char *name, int hp, int attack, int defense, int evasion, int accuracy, int speed, Move moves[], int move_count);
void init_all_moves(Move *all_moves);
void init_all_supemons(Supemon *supemons, Move *all_moves);
void level_up(Supemon *supemon);
void gain_experience(Supemon *supemon, int exp);

#endif
