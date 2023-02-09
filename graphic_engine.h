/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
  * @brief It creates a new graphic engine, allocating memory and initializing its members
  * @author Profesores PPROG
  * 
  * @return a pointer to the new graphic engine
  */
Graphic_engine *graphic_engine_create();

/**
  * @brief It destroys the game engine, freeing the allocated memory
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
void graphic_engine_destroy(Graphic_engine *ge);

/**
  * @brief It prints the game on the screen
  * @author Profesores PPROG
  * 
  * @param ge a pointer to the graphic engine
  * @param game a pointer to the game
  */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
