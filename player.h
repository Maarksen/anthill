/**
 * @brief It loads the game from a file
 *
 * @file player.h
 * @author Marek Buch
 * @version 1.0
 * @date 09-02-2023
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "object.h"


typedef struct Player player;

/**
  * @brief It creates a new player, allocating memory and initializing its members
  * @author Marek Buch
  *
  * @param id the identification number for the new space
  * @return a new player, initialized
  */
player* player_create(Id id, char *player_name);

/**
  * @brief It destroys a player that was already created
  * @author Marek Buch
  *
  * @param player a player structure we want to destroy
  * @return status report
  */
STATUS player_destroy(player *player);

/**
  * @brief It sets the atributes of a created player
  * @author Marek Buch
  *
  * @param id is the identification of the player
  * @param name is the name of the player
  * @param location is the location of the player
  * @param object is the object of the player
  * @return a player with set atributes
  */
player *player_set(player *player, Id id, char *name, Id location, Object *object);

/**
  * @brief It return a player
  * @author Marek Buch
  *
  * @param game where we are getting the player from
  * @return a player already existing
  */
player* player_get(Game *game);

/**
  * @brief It prints all atributes of a player
  * @author Marek Buch
  *
  * @param player player structure we want to print
  * @return a print message with player info
  */
STATUS player_print(player *player);


#ifndef SEED_SRC_PLAYER_H
#define SEED_SRC_PLAYER_H

#endif //SEED_SRC_PLAYER_H
