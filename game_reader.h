#ifndef GAME_READER_H
#define GAME_READER_H

#include "command.h"
#include "space.h"
#include "types.h"

typedef struct _Game {
  Id player_location;
  Id object_location;
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;
} Game;


STATUS game_add_space(Game *game, Space *space);
Space *game_get_space(Game *game, Id id);
Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);
Id game_get_player_location(Game *game);
Id game_get_object_location(Game *game); 


#endif