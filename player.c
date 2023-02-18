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

struct _Player{
    Id id;
    char *name;
    Id location;
    Object *object;
};

Player* player_create(Id id, char* player_name){
    Player *new_player = NULL;
    if(id == NO_ID){
        return NULL;
    }
    new_player = malloc(sizeof(Player));
    if(new_player == NULL){
        return NULL;
    }
    new_player->id = id;
    new_player->name = player_name;
    new_player->location = NO_ID;

    return new_player;
}

STATUS player_destroy(Player *player){
    if (!player) {
        return ERROR;
    }

    free(player);
    player = NULL;
    return OK;
}

Player *player_set(Player *player, Id id, char *name, Id location, Object *object){
    if(player == NULL){
        return NULL;
    }
    player->id = id;
    player->name = name;
    player->location = location;
    player->object = object;

    return player;
}

STATUS player_set_location(Player *player, Id id){
    if(player != NULL) {
        player->location = id;
        return OK;
    }
}

Id player_get_location(Player *player){
    if(player != NULL) {
        return player->location;
    }
}

STATUS player_print(Player *player){
    if(!player){
        return ERROR;
    }

    fprintf(stdout, "Player (ID: %ld Name: %s Location: %ld :Object: %d)\n", player->id, player->name, player->location, object_print(player->object));

    return OK;
}