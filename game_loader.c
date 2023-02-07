/**
 * @brief It loads the game from a file
 *
 * @file game_loader.c
 * @author Marek Buch
 * @version 1.0
 * @date 07-02-2023
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#inlclude "game_loader.h"


STATUS game_create_from_file(Game *game, char *filename) {
    if (game_create(game) == ERROR) {
        return ERROR;
    }

    if (game_load_spaces(game, filename) == ERROR) {
        return ERROR;
    }

    /* The player and the object are located in the first space */
    game_set_player_location(game, game_get_space_id_at(game, 0));
    game_set_object_location(game, game_get_space_id_at(game, 0));

    return OK;
}
