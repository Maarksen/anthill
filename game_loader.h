/**
 * @brief It loads the game from a file
 *
 * @file game_loader.h
 * @author Marek Buch
 * @version 1.0
 * @date 07-02-2023
 * @copyright GNU Public License
 */
#ifndef GAME_LOADER_H
#define GAME_LOADER_H

#include "game.h"
#include "game_reader.h"

STATUS game_create_from_file(Game *game, char *filename);

#endif