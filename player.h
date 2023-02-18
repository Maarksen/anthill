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
#include "object.h"

typedef struct Player{
    Id id;
    char *name;
    Id location;
    Object *object;
}player;

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
  * @brief It sets players location
  * @author Marek Buch
  *
  * @param player where we are getting the player from
  * @param id the location where to set the player
  * @return status
  */
STATUS player_set_location(player *player, Id id);

/**
  * @brief It returns players location
  * @author Marek Buch
  *
  * @param player where we are getting the player location from from
  * @return players location
  */
Id player_get_location(player *player);

/**
  * @brief It prints player
  * @author Marek Buch
  *
  * @param player where we are getting the player info from
  * @return player info
  */
STATUS player_print(player *player);


#ifndef SEED_SRC_PLAYER_H
#define SEED_SRC_PLAYER_H

#endif //SEED_SRC_PLAYER_H
