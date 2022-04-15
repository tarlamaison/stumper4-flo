/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Stumper
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_string.h"
#include "my.h"
#include "steumpeur.h"

static void free_pomekons(pomekon_t *pc_of_the_pokemon_center)
{
    pomekon_t *save_pc_of_the_pokemon_center = NULL;

    while (pc_of_the_pokemon_center) {
        save_pc_of_the_pokemon_center = pc_of_the_pokemon_center;
        pc_of_the_pokemon_center = pc_of_the_pokemon_center->next_node;
        free(save_pc_of_the_pokemon_center->name_of_the_pomekon);
        free(save_pc_of_the_pokemon_center);
    }
}

static bool choose_fight(pomekon_t *equip_of_the_trainer, char **array_of_args)
{
    pomekon_t *first = NULL;
    pomekon_t *second = NULL;
    pomekon_t *current = equip_of_the_trainer;

    if (my_strcmp(array_of_args[1], array_of_args[2]) == 0) {
        my_dprintf(2, "Error: You cant choose the same pokemon twice\n");
        return (false);
    }
    while (current != NULL) {
        if (my_strcmp(current->name_of_the_pomekon, array_of_args[1]) == 0)
            first = current;
        if (my_strcmp(current->name_of_the_pomekon, array_of_args[2]) == 0)
            second = current;
        current = current->next_node;
    }
    if (first == NULL || second == NULL)
        my_dprintf(2, "Error: Selected pokemon weren't found.\n");
    else
        fight_pomekons(equip_of_the_trainer, first, second);
    return (first != NULL && second != NULL);
}

int steumpeur(int number_of_args, char **array_of_args, char **ecosystem_array)
{
    bool fight = false;
    pomekon_t *pc_of_the_pokemon_center = NULL;

    if (ecosystem_array == NULL || ecosystem_array[0] == NULL) {
        my_dprintf(2, "Error: Environment is null\n");
        return (SUCCESS_EXIT);
    } else if (number_of_args != 3) {
        my_dprintf(2, "Error: You must choose two Pokemon\n");
        return (SUCCESS_EXIT);
    }
    if (!launch_folder_exploration(&pc_of_the_pokemon_center)) {
        return (SUCCESS_EXIT);
    } else if (pc_of_the_pokemon_center == NULL) {
        my_dprintf(2, "Error: You don't have any Pokemon\n");
        return (SUCCESS_EXIT);
    }
    fight = choose_fight(pc_of_the_pokemon_center, array_of_args);
    free_pomekons(pc_of_the_pokemon_center);
    return (fight ? FAILURE_EXIT : SUCCESS_EXIT);
}
