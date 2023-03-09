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

/**
  * @brief It executes the command unknown
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  */
void game_command_unknown(Game *game);

/**
  * @brief It executes the command exit
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  */
void game_command_exit(Game *game);
s [MAX_SPACES]
/**
  * @brief It executes STATUS game_set_player_location(Game *game, Id id);
Id game_get_player_location(Game *game);
Id game_get_object_location(Game *game, int pos); 
the command next
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  */
void game_command_next(Game *game);

/**
  * @brief It executes the command back
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  */
void game_command_back(Game *game);

/**
  * @brief It executes the command left
  * @author Ignacio Martin
  * 
  * @param game a pointer to the game
  */
void game_command_left(Game *game);

/**
  * @brief It executes the command right
  * @author Ignacio Martin
  * 
  * @param game a pointer to the game
  */
void game_command_right(Game *game);

/**
  * @brief It executes the command take
  * @author Ignacio Martin
  * 
  * @param game a pointer to the game
  */
void game_command_take(Game *game);

/**
  * @brief It executes the command drop
  * @author Ignacio Martin
  * 
  * @param game a pointer to the game
  */
void game_command_drop(Game *game);

/**
  * @brief It executes the command attack
  * @author Ignacio Martin
  * 
  * @param game a pointer to the game
  */
void game_command_attack(Game *game);

/**
   Game interface implementation
*/

/** game_create allocates memory for *!< Id number of the object location */a new game
  *  and initializes its members
  */
STATUS game_create(Game *game) {
  int i;

  /* Initialization of the spaces*/
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  /* Initialization of the player and the object*/
  game->player = player_create(1, "player");
  game->enemy = enemy_create(2, "enemy");
  game->object = object_create(3);
  game->object_location = NO_ID;

  game->last_cmd = NO_CMD;

  return OK;
}

/** game_destroy frees the previous memory allocation 
  *  for a game
  */
STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_destroy(game->spaces[i]);
  }
  player_destroy(game->player);
  enemy_destroy(game->enemy);
  object_destroy(game->object);

  return OK;
}

/** It sets the location of the player
  */
STATUS game_set_player_location(Game *game, Id id) {
    if (id == NO_ID) {
        return ERROR;
    }
    player_set_location(game->player, id);
    return OK;
}

/** It sets the location of the object
  */
STATUS game_set_object_location(Game *game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }
  
  game->object_location = id;
  object_set_id(game->object, id);
  space_set_object(game_get_space(game, id), TRUE);
  return OK;
}

/** It gets the location the player
  */
Id game_get_player_location(Game *game) {
  return player_get_location(game->player);
}

/** It gets the location the object
  */
Id game_get_object_location(Game *game, int pos) {
  return Set_getId_at(game->object, pos);
}

/** It updates the game
  */
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

    case LEFT:
      game_command_left(game);
      break;

    case RIGHT:
      game_command_right(game);
      break;

    case TAKE:
      game_command_take(game);
      break;

    case DROP:
      game_command_drop(game);
      break;

    case ATTACK:
      game_command_attack(game);
      break;

    default:
      break;
  }

  return OK;
}

/** It gets the last command
  */
T_Command game_get_last_command(Game *game) {
  return game->last_cmd;
}

/** It prints the data of the game
  */
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

/** It is executed when the game is over
  */
BOOL game_is_over(Game *game) {
  Id hp_player = player_get_hp(game->player);

  if (hp_player <= 0){
    return TRUE;
  }
  
  return FALSE;
}

/**
   Calls implementation for each action 
*/

/** It executes the command unknown
  */
void game_command_unknown(Game *game) {
}

/** It executes the command exit
  */
void game_command_exit(Game *game) {
}

/** It executes the command next
  */
void game_command_next(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  /* Error control */
  if (space_id == NO_ID) {
    return;
  }

  /* Moves the player to the south */
  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return;
}

/** It executes the command back
  */
void game_command_back(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  /* Error control */
  if (NO_ID == space_id) {
    return;
  }

  /* Moves the player to the north */
  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return;
}

/** It executes the command left
  */
void game_command_left(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  /* Error control */
  if (NO_ID == space_id) {
    return;
  }

  /* Moves the player to the west */
  current_id = space_get_east(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return;
}

/** It executes the command right
  */
void game_command_right(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  /* Error control */
  if (NO_ID == space_id) {
    return;
  }

  /* Moves the player to the east */
  current_id = space_get_west(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return;
}

/** It executes the command take
  */
void game_command_take(Game *game) {
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  /* Error control */
  if (NO_ID == space_id) {
    return;
  }

  /** If the player is in the same location as the 
    * object, the player takes the object 
    */
  if (space_get_object(game_get_space(game, space_id))) {
    player_set_object(game->player, TRUE);
    space_set_object(game_get_space(game, space_id), FALSE);
    game_set_object_location(game, player_get_id(game->player));
  }
  
  return;
}

/** It executes the command drop
  */
void game_command_drop(Game *game) {
  Id space_id = NO_ID;
  BOOL object = FALSE;

  space_id = game_get_player_location(game);
  object = player_get_object(game->player);

  /* Error control */
  if (NO_ID == space_id || !object) {
    return;
  }

  /** The player drops the object
    * in the space they are
    */
  space_set_object(game_get_space(game, space_id), TRUE);
  player_set_object(game->player, FALSE);
  game_set_object_location(game, space_id);
  
  
  return;
}

/** It executes the command attack
  */
void game_command_attack(Game *game) {
  Id hp_player, hp_enemy;
  int r;

  hp_player = player_get_hp(game->player);
  hp_enemy = enemy_get_hp(game->enemy);

  r = rand() % (hp_enemy + hp_player);

  if (r > hp_enemy) {
    //win
    enemy_set_hp(game->enemy, 0);
  } else {
    //lose
  player_set_hp(game->player, 0);
    game_is_over(game);
  }

  return;
}