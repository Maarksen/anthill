/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 30-11-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graphic_engine.h"
#include "game.h"
#include "game_reader.h"
#include "command.h"

/**
  * @brief It creates a new game loop and initializes the game and the graphic engine
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param gengine a double pointer to the graphic engine
  * @param file_name a string with the data for the game
  * @return 0 if everything goes well, 1 if not
  */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
  * @brief It runs the game loop
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param gengine a pointer to the graphic engine
  */
void game_loop_run(Game game, Graphic_engine *gengine);

/**
  * @brief It destroys the game and the graphic engine
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @param gengine a pointer to the graphic engine
  */
void game_loop_cleanup(Game game, Graphic_engine *gengine);

/** main function creates the game loop,
  *  runs the game loop and 
  *  finally it cleans up
  */
int main(int argc, char *argv[]) {
  Game game;
  Graphic_engine *gengine;

  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
 
  if (!game_loop_init(&game, &gengine, argv[1])) {
    game_loop_run(game, gengine);
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

/** game_loop_init initializes the game loop,
  *  creates the game and the graphic engine
  */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name) {
  srand(time(NULL));

  if (game_create_from_file(game, file_name) == ERROR) {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL) {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

/** game_loop_run runs the game loop,
  *  executes commands, updates the game
  *  and the graphic engine
  */
void game_loop_run(Game game, Graphic_engine *gengine) {
  T_Command command = NO_CMD;

  while ((command != EXIT) && !game_is_over(&game)) {
    graphic_engine_paint_game(gengine, &game);
    command = command_get_user_input();
    game_update(&game, command);
  }
}

/** game_loop_cleanup destroys the game
  *  and the game engine
  */
void game_loop_cleanup(Game game, Graphic_engine *gengine) {
  game_destroy(&game);
  graphic_engine_destroy(gengine);
}
