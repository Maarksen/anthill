#ifndef GAME_READER_H
#define GAME_READER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"

STATUS game_load_spaces(Game *game, char *filename);
STATUS game_add_space(Game *game, Space *space);
Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);
STATUS game_set_object_location(Game *game, Id id);
Space *game_get_space(Game *game, Id id);
Id game_get_player_location(Game *game);
Id game_get_object_location(Game *game);


#endif