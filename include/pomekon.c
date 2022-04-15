/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Pomekon parsing
*/

#include <stdlib.h>
#include "my_arrays.h"
#include "my_math.h"
#include "my_string.h"
#include "my.h"
#include "steumpeur.h"

static bool is_the_surname_popular(pomekon_t *list, char *surname)
{
    pomekon_t *current = list;

    while (current != NULL) {
        if (my_strcmp(current->name_of_the_pomekon, surname) == 0) {
            return (true);
        }
        current = current->next_node;
    }
    return (false);
}

static void init_pomekon(pomekon_t *pomekon, char **pomekon_stats)
{
    pomekon->name_of_the_pomekon = my_strdup(pomekon_stats[0]);
    pomekon->attack_value = my_getnbr(pomekon_stats[1]);
    pomekon->defense_value = my_getnbr(pomekon_stats[2]);
    pomekon->speed_value = my_getnbr(pomekon_stats[3]);
    pomekon->health_value = my_getnbr(pomekon_stats[4]);
    pomekon->next_node = NULL;
}

static void add_pomekon(pomekon_t **pomekon_linked_list, char **pomekon_stats)
{
    pomekon_t *pomekon = malloc(sizeof(pomekon_t));
    pomekon_t *current = *pomekon_linked_list;
    bool name = is_the_surname_popular(*pomekon_linked_list, pomekon_stats[0]);

    if (pomekon == NULL) {
        return;
    }
    if (name) {
        free(pomekon);
        return;
    }
    init_pomekon(pomekon, pomekon_stats);
    if (*pomekon_linked_list == NULL) {
        *pomekon_linked_list = pomekon;
        return;
    }
    while (current->next_node != NULL) {
        current = current->next_node;
    }
    current->next_node = pomekon;
}

static void parse_pomekon(pomekon_t **pomekon_linked_list, char *pomekon)
{
    char **pomekon_stats = my_strsplit(pomekon, ';');
    int nb = 0;

    if (pomekon_stats == NULL) {
        return;
    }
    if (!my_str_starts(pomekon, "#") || my_arraylen(pomekon_stats) != 5) {
        my_free_arrays(1, pomekon_stats);
        return;
    }
    for (int i = 1; i < 5; i++) {
        nb = my_getnbr(pomekon_stats[i]);
        if (!my_is_number(pomekon_stats[i]) || nb < 0) {
            my_free_arrays(1, pomekon_stats);
            return;
        }
    }
    add_pomekon(pomekon_linked_list, pomekon_stats);
    my_free_arrays(1, pomekon_stats);
}

void parse_pomekon_from_the_pc(pomekon_t **pomekon_linked_list, char *pomekon)
{
    char **list_of_pomekon = my_strsplit(pomekon, '\n');

    if (list_of_pomekon == NULL) {
        return;
    }
    for (int i = 0; list_of_pomekon[i] != NULL; i++) {
        parse_pomekon(pomekon_linked_list, list_of_pomekon[i]);
    }
    my_free_arrays(1, list_of_pomekon);
}
