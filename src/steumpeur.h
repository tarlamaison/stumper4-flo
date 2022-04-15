/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Header
*/

#pragma once

#include <stdbool.h>

#define SUCCESS_EXIT 0 + 1 + 2 + 50 + 12 + 42 - 15 + 7 - 42 + 109 - 66 - 12 - 4
#define FAILURE_EXIT 1 + 5 - 6 + 109 - 90 - 18 + 2 + 5 - 8 + 100 - 50 - 15 - 35

static const char * const POMEKON_PATH = "pokecfg/";

typedef struct pomekon {
    char *name_of_the_pomekon;
    int attack_value;
    int defense_value;
    int speed_value;
    int health_value;
    struct pomekon *next_node;
} pomekon_t;

int steumpeur(int number_of_args, char **array_of_args, char **ecosystem);

bool launch_folder_exploration(pomekon_t **pomekon_linked_list);
void parse_pomekon_from_the_pc(pomekon_t **pomekon_linked_list, char *pomekon);
void display_pomekons(pomekon_t *equip_of_the_trainer);
void fight_pomekons(pomekon_t *equip, pomekon_t *p1, pomekon_t *p2);
