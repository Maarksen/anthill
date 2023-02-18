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

STATUS player_set_location(player *player, Id id){
    if(player != NULL) {
        player->location = id;
        return OK;
    }
}

Id player_get_location(player *player){
    if(player != NULL) {
        return player->location;
    }
}

STATUS player_print(player *player){
    if(!player){
        return ERROR;
    }

    fprintf(stdout, "Player (ID: %ld Name: %s Location: %ld :Object: %d)\n", player->id, player->name, player->location, object_print(player->object));

    return OK;
}