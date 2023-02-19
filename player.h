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

Player* player_create(Id id, char* player_name);

/**
  * @brief It destroys a player that was already created
  * @author Marek Buch
  *
  * @param player a player structure we want to destroy
  * @return status report
  */
STATUS player_destroy(Player *player);

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
Player *player_set(Player *player, Id id, char *name, Id location, BOOL object);

/**
  * @brief It sets players location
  * @author Marek Buch
  *
  * @param player where we are getting the player from
  * @param id the location where to set the player
  * @return status
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

Id player_get_id(Player *player);
STATUS player_set_object(Player *player, BOOL object);
BOOL player_get_object(Player *player);

/**
  * @brief It prints player
  * @author Marek Buch
  *
  * @param player where we are getting the player info from
  * @return player info
  */
STATUS player_print(Player *player);

#endif 