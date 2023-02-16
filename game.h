/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"

/**
 * @brief Game
 *
 * This struct stores all the information of a game.
 */
typedef struct Game {
  Id object_location;
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;
  player *player1;
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
  * @brief It creates a new game, with the data from a file
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param filename a character pointer to the name of the file
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
/*STATUS game_create_from_file(Game *game, char *filename);*/

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
  * @brief It adds a new space to the game
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param space a pointer to the new space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_add_space(Game *game, Space *space);

/**
  * @brief It gets a pointer to the space with the id
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param id the id of the space
  * @return a pointer to the space, if everything goes well or NULL if there was some mistake
  */
Space *game_get_space(Game *game, Id id);

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
Id game_get_object_location(Game *game);

/**
  * @brief It gets the last executed command
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @return the last command
  */
T_Command game_get_last_command(Game *game);

player* player_get(Game *game);

/**
  * @brief It prints all atributes of a player
  * @author Marek Buch
  *
  * @param player player structure we want to print
  * @return a print message with player info
  */
#endif
