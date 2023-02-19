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

/**
  * @brief It creates a new game, with the data from a file
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param filename a character pointer to the name of the file
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_create_from_file(Game *game, char *filename);

#endif