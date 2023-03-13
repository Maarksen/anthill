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

/** game_create allocates memory for a new game
  *  and initializes its members
  */
STATUS game_create(Game *game) {
  int i;

  /* Initialization of the spaces and objects*/
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
    game->objects[i] = NULL;
  }

  /* Initialization of the player and the enemy*/
  game->player = player_create(1, "player");
  game->enemy = enemy_create(2, "enemy");

  game->last_cmd = NO_CMD;

  //enemy_testing();

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
  for (i = 0; i < MAX_OBJ && game->objects[i] != NULL; i++) {
    object_destroy(game->objects[i]);
  }
  player_destroy(game->player);
  enemy_destroy(game->enemy);

  return OK;
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

  printf("=> Objects: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    object_print(game->objects[i]);
  }

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
  int i;
  Object *ob;

  for(i=0;i<MAX_SPACES;i++){
    ob = game_get_object(game, i);
    if(player_get_object(game->player)==NO_ID && ob != NULL){
      player_set_object(game->player, ob);
      space_set_object(game->spaces[i], NO_ID);
      return;
    }
  }

  return;
  

}

/** It executes the command drop
  */
void game_command_drop(Game *game) {
  Id space_id = NO_ID;
  Id object_id = NO_ID;

  space_id = game_get_player_location(game);
  object_id = player_get_object(game->player);

  /* Error control */
  if (NO_ID == space_id || NO_ID == object_id) {
    return;
  }

  /** The player drops the object
    * in the space they are
    */
  space_set_object(game_get_space(game, space_id), object_id);
  player_set_object(game->player, FALSE);
  for(int i =0; i< MAX_SPACES; i++){
      if(object_id == object_get_id(game->objects[i])){
        game_set_object_location(game, player_get_id(game->player), i);
        return;
      }
    }
  
  
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