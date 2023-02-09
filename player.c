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

typedef struct Player{
    Id id;
    char *name;
    Id location;
    Object *object;
}player;

player* player_create(Id id, char* player_name){
    player *new_player = NULL;
    if(id == NO_ID){
        return NULL;
    }
    new_player = malloc(sizeof(player));
    if(new_player == NULL){
        return NULL;
    }

    new_player->id = id;
    new_player->name = player_name;
    new_player->location = 1;
    new_player->object = NULL;

    return new_player;
}

STATUS player_destroy(player *player){
    if (!player) {
        return ERROR;
    }

    free(player);
    player = NULL;
    return OK;
}

player *player_set(player *player, Id id, char *name, Id location, Object *object){
    if(player == NULL){
        return NULL;
    }
    player->id = id;
    player->name = name;
    player->location = location;
    player->object = object;

    return player;
}

player* player_get(Game *game){
    return game->player;
}

STATUS player_print(player *player){
    if(!player){
        return NULL;
    }

    fprintf(stdout, "Player (ID: %ld Name: %s Location: %ld :Object: %d)\n", player->id, player->name, player->location, object_print(player->object));

    return OK;
}