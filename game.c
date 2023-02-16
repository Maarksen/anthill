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
//STATUS game_load_spaces(Game *game, char *filename);
/*STATUS game_add_space(Game *game, Space *space);
Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);
Id game_get_player_location(Game *game);
STATUS game_set_object_location(Game *game, Id id);*/

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);

/**
   Game interface implementation
*/

STATUS game_create(Game *game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  game->player1 = NULL;
  game->object_location = NO_ID;
  game->last_cmd = NO_CMD;

  return OK;
}

/*
STATUS game_create_from_file(Game *game, char *filename) {
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_load_spaces(game, filename) == ERROR) {
    return ERROR;
  }

  //The player and the object are located in the first space
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}
*/

STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_destroy(game->spaces[i]);
  }

  return OK;
}

STATUS game_add_space(Game *game, Space *space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL) {
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game *game, int position) {
  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}

STATUS game_set_player_location(Game *game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }

    player_set_location(game->player1, id);

  return OK;
}

STATUS game_set_object_location(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return ERROR;
  }
  
  game->object_location = id;
  space_set_object(game_get_space(game, id), TRUE);
}

Id game_get_player_location(Game *game) {
  return player_get_location(game->player1);
}

Id game_get_object_location(Game *game) {
  return game->object_location;
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
  printf("=> Player location: %d\n", (int)player_get_location(game->player1));
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

  if (space_get_object(game->spaces[space_id])) {
    player_set_object(game->player1, game->object_location);
  }
  
  return;
}

void game_command_drop(Game *game) {
  Id space_id = NO_ID;
  Id object_id = NO_ID;

  space_id = game_get_player_location(game);
  object_id = player_get_object(game->player1);

  if (NO_ID == space_id || NO_ID == object_id) {
    return;
  }

  if (space_set_object(game->spaces[space_id], object_id)) {
    player_set_object(game->player1, NO_ID);
  }
  
  return;
}

player* player_get(Game *game){
    return game->player1;
}
/*
STATUS game_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}
*/