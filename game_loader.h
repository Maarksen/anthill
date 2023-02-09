/**
 * @brief It loads the game from a file
 *
 * @file game_loader.h
 * @author Marek Buch
 * @version 1.0
 * @date 07-02-2023
 * @copyright GNU Public License
 */

#include "game.h"

#ifndef SEED_SRC_GAME_LOADER_H
#define SEED_SRC_GAME_LOADER_H

STATUS game_create_from_file(Game *game, char *filename);
STATUS game_load_spaces(Game *game, char *filename);


#endif //SEED_SRC_GAME_LOADER_H
