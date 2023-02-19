/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 3.0 
 * @date 26-01-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

/**
   Private functions
*/
void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);
void game_command_take(Game *game);
void game_command_drop(Game *game);

/**
   Game interface implementation
*/

STATUS game_create(Game *game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  game->player = player_create(1, "player");
  game->object_location = NO_ID;
  game->last_cmd = NO_CMD;

  return OK;
}

STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_destroy(game->spaces[i]);
  }
  player_destroy(game->player);

  return OK;
}

STATUS game_update(Game *game, T_Command cmd) {
  game->last_cmd = cmd;
  
  switch (cmd) {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game_command_next(game);
      break;

    case BACK:
      game_command_back(game);
      break;

    case TAKE:
      game_command_take(game);
      break;

    case DROP:
      game_command_drop(game);
      break;

    default:
      break;
  }

  return OK;
}

T_Command game_get_last_command(Game *game) {
  return game->last_cmd;
}

void game_print_data(Game *game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game->object_location);
  printf("=> Player location: %d\n", (int)player_get_location(game->player));
}

BOOL game_is_over(Game *game) {
  return FALSE;
}

/**
   Calls implementation for each action 
*/
void game_command_unknown(Game *game) {
}

void game_command_exit(Game *game) {
}

void game_command_next(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return;
}

void game_command_back(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return;
  }

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return;
}

void game_command_take(Game *game) {
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return;
  }

  if (space_get_object(game_get_space(game, space_id))) {
    player_set_object(game->player, TRUE);
    space_set_object(game_get_space(game, space_id), FALSE);
    game_set_object_location(game, player_get_id(game->player));
  }
  
  return;
}

void game_command_drop(Game *game) {
  Id space_id = NO_ID;
  BOOL object = FALSE;

  space_id = game_get_player_location(game);
  object = player_get_object(game->player);

  if (NO_ID == space_id || !object) {
    return;
  }

  space_set_object(game_get_space(game, space_id), TRUE);
  player_set_object(game->player, FALSE);
  game_set_object_location(game, space_id);
  
  
  return;
}

Player* player_get(Game *game){
    return game->player;
}
