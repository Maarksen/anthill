/**
 * @brief It loads the game from a file
 *
 * @file player.c
 * @author Marek Buch
 * @version 1.0
 * @date 09-02-2023
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */
struct _Player{
    Id id;          /*!< Id number of the player, it must be unique */
    char *name;     /*!< String with the name of the player */
    Id location;    /*!< Id number of the space where the player is*/
    int health;     /*!< int health of a player*/
    BOOL object;    /*!< Whether the player has an object or not */
};

/** player_create allocates memory for a new player
  *  and initializes its members
  */
Player* player_create(Id id, char* player_name){
    Player *new_player = NULL;

    /* Error Control */
    if(id == NO_ID){
        return NULL;
    }

    new_player = malloc(sizeof(Player));
    /* Error Control */
    if(new_player == NULL){
        return NULL;
    }
    /* Initialization of a new player */
    new_player->id = id;
    new_player->name = player_name;
    new_player->health = 100;
    new_player->location = NO_ID;

    return new_player;
}

/** space_destroy frees the previous memory allocation 
  *  for a player
  */
STATUS player_destroy(Player *player){
    /* Error Control */
    if (!player) {
        return ERROR;
    }

    free(player);
    player = NULL;
    return OK;
}

/** It sets the properties of a player
  */
Player *player_set(Player *player, Id id, char *name, Id location, int hp, BOOL object){
    /* Error Control */
    if(player == NULL){
        return NULL;
    }
    /* Sets all the properties */
    player->id = id;
    player->name = name;
    player->location = location;
    player->object = object;
    player->health = hp;

    return player;
}

/** It sets the location of a player
  */
STATUS player_set_location(Player *player, Id id){
    if(player != NULL) {
        player->location = id;
        return OK;
    }
    return ERROR;
}

/** It gets the location of a player
  */
Id player_get_location(Player *player){
    if(player != NULL) {
        return player->location;
    }
    return NO_ID;
}

/** It gets the id of a player
  */
Id player_get_id(Player *player){
    if(player != NULL) {
        return player->id;
    }
    return NO_ID;
}

/** It sets the health of a player
*/
STATUS player_set_hp(Player *player, int hp){
    if(player != NULL) {
        player->health = hp;
        return OK;
    }
    return ERROR;
}

/** It gets the health of a player
  */
Id player_get_hp(Player *player){
    if(player != NULL) {
        return player->health;
    }
    return NO_ID;
}

/** It sets whether the player has an object or not
  */
STATUS player_set_object(Player *player, BOOL object){
    if(player != NULL) {
        player->object = object;
        return OK;
    }
    return ERROR;
}

/** It gets whether the player has an object or not
  */
BOOL player_get_object(Player *player){
    if(player != NULL) {
        return player->object;
    }
    return FALSE;
}

/** It prints the player information
  */
STATUS player_print(Player *player){
    /* Error Control */
    if(!player){
        return ERROR;
    }

    fprintf(stdout, "Player (ID: %ld Name: %s Location: %ld :Object: %s)\n", player->id, player->name, player->location, (player->object ? "True" : "False"));

    return OK;
}