/**
 * @brief It loads the game from a file
 *
 * @file player.h
 * @author Marek Buch
 * @version 1.0
 * @date 09-02-2023
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

typedef struct _Player Player;

/**
  * @brief It creates a player, allocating memory and initializing its members
  * @author Marek Buch
  *
  * @param id of the new player 
  * @param player_name a string with the name of the new player
  * @return a pointer to the player if everything goes well or NULL if there was some mistakes
  */
Player *player_create(Id id, char* player_name);

/**
  * @brief It destroys a player that was already created
  * @author Marek Buch
  *
  * @param player a player structure we want to destroy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_destroy(Player *player);

/**
  * @brief It sets the atributes of a created player
  * @author Marek Buch
  *
  * @param id is the identification of the player
  * @param name is the name of the player
  * @param location is the location of the player
  * @param object a boolean, specifying if the player has an object (TRUE) or not (FALSE)
  * @return a player with set atributes
  */
Player *player_set(Player *player, Id id, char *name, Id location, int hp, Object *object);

/**
  * @brief It sets players location
  * @author Marek Buch
  *
  * @param player where we are getting the player from
  * @param id the location where to set the player
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_location(Player *player, Id id);

/**
  * @brief It returns players location
  * @author Marek Buch
  *
  * @param player where we are getting the player location from from
  * @return players location
  */
Id player_get_location(Player *player);

/**
  * @brief It returns the id of the player
  * @author Marek Buch
  *
  * @param player a pointer to the player
  * @return the id of the player
  */
Id player_get_id(Player *player);

/**
  * @brief It sets the health of the enemy
  * @author Marek Buch
  *
  * @param enemy a pointer to the enemy
  * @param hp the health for the enemy
  * @return the health of the enemy
  */
STATUS player_set_hp(Player *player, int hp);

/**
  * @brief It returns the health of the enemy
  * @author Marek Buch
  *
  * @param enemy a pointer to the enemy
  * @return the health of the enemy
  */
Id player_get_hp(Player *player);

/**
  * @brief It sets whether the player has an object or not
  * @author Marek Buch
  *
  * @param player a pointer to the player
  * @param object a boolean, specifying if the player has an object (TRUE) or not (FALSE)
  * @return OK, if everything goes well or ERROR if there was some mistake
  */

STATUS player_set_object(Player *player, Object *object);

/**
  * @brief It gets whether the player has an object or not
  * @author Marek Buch
  *
  * @param player a pointer to the player
  * @return a boolean, specifying if in the space there is an object (TRUE) or not (FALSE)
  */
Id player_get_object(Player *player);

/**
  * @brief It prints player
  * @author Marek Buch
  *
  * @param player where we are getting the player info from
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_print(Player *player);

#endif 