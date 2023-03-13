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

#define MAX_OBJ 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "space.h"
#include "Set.h"
#include "object.h"

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
  * @brief It loads the objects of a game
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param filename a string with the name of the file with the anthill
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_load_objects(Game *game, char *filename);

/**
  * @brief It adds a new object to the game
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param object a pointer to the new object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_add_object(Game *game, Object *object);

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

STATUS game_create_from_file(Game *game, char *filename);
STATUS game_set_object_location(Game *game, Id id, int pos);
STATUS game_set_player_location(Game *game, Id id);
Id game_get_player_location(Game *game);
Id game_get_object_location(Game *game, int pos); 
Object *game_get_object(Game *game, int i);


#endif