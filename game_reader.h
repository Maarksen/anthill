/**
 * @brief It defines the functions that load the spaces
 *
 * @file game_reader.h
 * @author Daniel Cabrero
 * @version 1.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"

/**
  * @brief It loads the spaces of a game
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param filename a string with the name of the file with the anthill
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_load_spaces(Game *game, char *filename);

/**
  * @brief It adds a new space to the game
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param space a pointer to the new space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_add_space(Game *game, Space *space);

/**
  * @brief It gets the id of a position of the game
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param position the position 
  * @return the id of the position
  */
Id game_get_space_id_at(Game *game, int position);

/**
  * @brief It gets a pointer to the space with the id
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param id the id of the space
  * @return a pointer to the space, if everything goes well or NULL if there was some mistake
  */
Space *game_get_space(Game *game, Id id);

STATUS game_set_player_location(Game *game, Id id);
Id game_get_player_location(Game *game);
Id game_get_object_location(Game *game, int pos); 


#endif