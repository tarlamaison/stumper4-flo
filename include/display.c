/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Display
*/

#include "steumpeur.h"
#include "my.h"

void display_pomekons(pomekon_t *equip_of_the_trainer)
{
    char *format = "Pokemon %s has %d attack, %d defense, %d speed" \
        " and %d health\n";
    char *name = 0;
    int attack = 0;
    int defense = 0;
    int speed = 0;
    int health = 0;

    while (equip_of_the_trainer) {
        name = equip_of_the_trainer->name_of_the_pomekon;
        attack = equip_of_the_trainer->attack_value;
        defense = equip_of_the_trainer->defense_value;
        speed = equip_of_the_trainer->speed_value;
        health = equip_of_the_trainer->health_value;
        my_printf(format, name, attack, defense, speed, health);
        equip_of_the_trainer = equip_of_the_trainer->next_node;
    }
}
