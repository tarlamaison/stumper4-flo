/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Files parsing
*/

#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_string.h"
#include "my.h"
#include "steumpeur.h"

static char *get_pokeballs(char *box_in_the_pc, int size_of_the_box)
{
    char *content = NULL;
    int fd = open(box_in_the_pc, O_RDONLY);
    int re = 0;

    if (fd == -1)
        return (NULL);
    content = malloc(sizeof(char) * (size_of_the_box) + 1);
    if (content == NULL) {
        close(fd);
        return (NULL);
    }
    re = read(fd, content, size_of_the_box);
    if (re == -1) {
        close(fd);
        free(content);
        return (NULL);
    }
    content[re] = '\0';
    close(fd);
    return (content);
}

static void open_pokeball(pomekon_t **pomekon_linked_list, char *box_in_the_pc)
{
    int st = 0;
    char *stack_of_pokeballs = my_strcat(POMEKON_PATH, box_in_the_pc);
    char *content = NULL;
    struct stat pokestats;

    if (stack_of_pokeballs == NULL)
        return;
    st = stat(stack_of_pokeballs, &pokestats);
    if (st == -1) {
        free(stack_of_pokeballs);
        return;
    }
    content = get_pokeballs(stack_of_pokeballs, pokestats.st_size);
    if (content == NULL) {
        free(stack_of_pokeballs);
        return;
    }
    parse_pomekon_from_the_pc(pomekon_linked_list, content);
    my_free(2, stack_of_pokeballs, content);
}

static bool is_folder(char *box_in_the_pc)
{
    int place = my_strcmp(box_in_the_pc, ".");
    int previous = my_strcmp(box_in_the_pc, "..");

    return (place == 0 || previous == 0);
}

bool launch_folder_exploration(pomekon_t **pomekon_linked_list)
{
    DIR *dir = opendir(POMEKON_PATH);
    struct dirent *dp;

    if (dir == NULL) {
        my_dprintf(2, "Error: Folder %s does not exist\n", POMEKON_PATH);
        return (false);
    }
    while ((dp = readdir(dir)) != NULL) {
        if (!is_folder(dp->d_name)) {
            open_pokeball(pomekon_linked_list, dp->d_name);
        }
    }
    closedir(dir);
    return (true);
}
