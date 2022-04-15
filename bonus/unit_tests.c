/*
** EPITECH PROJECT, 2022
** duostumper4
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "steumpeur.h"

Test(win_handling, win_one_attack, .init=cr_redirect_stdout)
{
    pomekon_t p1 = { "Tekepi", 65, 4, 34, 100, 0 };
    pomekon_t p2 = { "Etipek", 4, 35, 2, 13, 0 };

    fight_pomekons(NULL, &p1, &p2);
    cr_assert_stdout_eq_str("Tekepi attacks for 65 damage\n"
                            "Etipek blocks 35 damage\n"
                            "Etipek loses 30 health (0 left)\n"
                            "Etipek is KO\n"
                            "Tekepi wins the fight!\n");
}

Test(win_handling, p2_win, .init=cr_redirect_stdout)
{
    pomekon_t p1 = { "Tekepi", 5, 3, 4, 100, 0 };
    pomekon_t p2 = { "Etipek", 40, 2, 1, 100, 0 };

    fight_pomekons(NULL, &p1, &p2);
    cr_assert_stdout_eq_str("Tekepi attacks for 5 damage\n"
                            "Etipek blocks 2 damage\n"
                            "Etipek loses 3 health (97 left)\n"
                            "Etipek attacks for 40 damage\n"
                            "Tekepi blocks 3 damage\n"
                            "Tekepi loses 37 health (63 left)\n"
                            "Tekepi attacks for 5 damage\n"
                            "Etipek blocks 2 damage\n"
                            "Etipek loses 3 health (94 left)\n"
                            "Etipek attacks for 40 damage\n"
                            "Tekepi blocks 3 damage\n"
                            "Tekepi loses 37 health (26 left)\n"
                            "Tekepi attacks for 5 damage\n"
                            "Etipek blocks 2 damage\n"
                            "Etipek loses 3 health (91 left)\n"
                            "Etipek attacks for 40 damage\n"
                            "Tekepi blocks 3 damage\n"
                            "Tekepi loses 37 health (0 left)\n"
                            "Tekepi is KO\n"
                            "Etipek wins the fight!\n");
}

Test(win_handling, p2_start, .init=cr_redirect_stdout)
{
    pomekon_t p1 = { "Tekepi", 65, 4, 34, 100, 0 };
    pomekon_t p2 = { "Etipek", 4, 35, 200, 13, 0 };

    fight_pomekons(NULL, &p1, &p2);
    cr_assert_stdout_eq_str("Etipek attacks for 4 damage\n"
                            "Tekepi blocks 4 damage\n"
                            "Tekepi loses 0 health (100 left)\n"
                            "Tekepi attacks for 65 damage\n"
                            "Etipek blocks 35 damage\n"
                            "Etipek loses 30 health (0 left)\n"
                            "Etipek is KO\n"
                            "Tekepi wins the fight!\n");
}

Test(win_handling, defense_superior_loses, .init=cr_redirect_stdout)
{
    pomekon_t p1 = { "Tekepi", 65, 6, 34, 100, 0 };
    pomekon_t p2 = { "Etipek", 4, 35, 200, 13, 0 };

    fight_pomekons(NULL, &p1, &p2);
    cr_assert_stdout_eq_str("Etipek attacks for 4 damage\n"
                            "Tekepi blocks 6 damage\n"
                            "Tekepi loses 0 health (100 left)\n"
                            "Tekepi attacks for 65 damage\n"
                            "Etipek blocks 35 damage\n"
                            "Etipek loses 30 health (0 left)\n"
                            "Etipek is KO\n"
                            "Tekepi wins the fight!\n");
}

Test(display_handling, display, .init=cr_redirect_stdout)
{
    pomekon_t p2 = { "Etipek", 4, 35, 200, 13, 0 };
    pomekon_t p1 = { "Tekepi", 65, 6, 34, 100, &p2 };

    display_pomekons(&p1);
    cr_assert_stdout_eq_str("Pokemon Tekepi has 65 attack, 6 defense,"
                            " 34 speed and 100 health\n"
                            "Pokemon Etipek has 4 attack, 35 defense,"
                            " 200 speed and 13 health\n");
}
