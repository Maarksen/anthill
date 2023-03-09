/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include "game_reader.h"
#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"
#include "object.h"
#include "enemy.h"

/**
 * @brief Game
 *
 * This struct stores all the information of a game.
 */
typedef struct _Game {         
  Space *spaces[MAX_SPACES];  /*!< Array with all the spaces in the game */
  T_Command last_cmd;         /*!< Enum value of the last command */
  Player *player;             /*!< A pointer to the object */
  Object *object;             /*!< A pointer to the player */
  Enemy *enemy;
} Game;

/**
  * @brief It creates a new game, allocating memory and initializing its members
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_create(Game *game);

/**
  * @brief It updates the game, with the command executed
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param cmd a command to be executed
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_update(Game *game, T_Command cmd);

/**
  * @brief It destroys a game, freeing the allocated memory
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game that must be destroyed
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_destroy(Game *game);

/**
  * @brief It is executed when the game is over
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @return a boolean, specifying that the game is over (FALSE)
  */
BOOL game_is_over(Game *game);

/**
  * @brief It prints a game, with the spaces, player and objects
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game that must be printed
  */
void game_print_data(Game *game);

/**
  * @brief It sets the location of the player to the id
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param id the id of the new position
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_player_location(Game *game, Id id);

/**
  * @brief It gets the id of a player location
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @return the id of the player location
  */
Id game_get_player_location(Game *game);

/**
  * @brief It sets the object location
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param id the id of the location
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_object_location(Game *game, Id id);

/**
  * @brief It gets the id of an object location
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @return the id of the object location
  */
Id game_get_object_location(Game *game, int pos);

/**
  * @brief It gets the last executed command
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @return the last command
  */
T_Command game_get_last_command(Game *game);

#endif
