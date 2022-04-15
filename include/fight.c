/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Fight
*/

#include "steumpeur.h"
#include "my.h"

static void switch_role(pomekon_t **attacker, pomekon_t **defenser)
{
    pomekon_t *save_attacker = *attacker;

    *attacker = *defenser;
    *defenser = save_attacker;
}

static void victory_log(pomekon_t *winner, pomekon_t *looser)
{
    my_printf("%s is KO\n", looser->name_of_the_pomekon);
    my_printf("%s wins the fight!\n", winner->name_of_the_pomekon);
}

static void pika_pika(pomekon_t *attacker, pomekon_t *defenser)
{
    char *attacker_name = attacker->name_of_the_pomekon;
    int attacker_attack = attacker->attack_value;
    char *defenser_name = defenser->name_of_the_pomekon;
    int defenser_defense = defenser->defense_value;
    int loses = attacker_attack - defenser_defense;
    int health = 0;

    if (loses < 0)
        loses = 0;
    defenser->health_value -= loses;
    if (defenser->health_value > 0)
        health = defenser->health_value;
    my_printf("%s attacks for %d damage\n", attacker_name, attacker_attack);
    my_printf("%s blocks %d damage\n", defenser_name, defenser_defense);
    my_printf("%s loses %d health (%d left)\n", defenser_name, loses, health);
}

void fight_pomekons(pomekon_t *equip, pomekon_t *p1, pomekon_t *p2)
{
    pomekon_t *attacker = p1;
    pomekon_t *defenser = p2;
    int playing = 1;

    display_pomekons(equip);
    if (p2->speed_value > p1->speed_value)
        switch_role(&attacker, &defenser);
    while (playing) {
        pika_pika(attacker, defenser);
        if (defenser->health_value <= 0)
            playing = 0;
        else
            switch_role(&attacker, &defenser);
    }
    victory_log(attacker, defenser);
}
