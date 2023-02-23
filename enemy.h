/**
 * @brief It loads the game from a file
 *
 * @file enemy.h
 * @author Marek Buch
 * @version 1.0
 * @date 09-02-2023
 * @copyright GNU Public License
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

typedef struct _Enemy Enemy;

/**
  * @brief It creates a enemy, allocating memory and initializing its members
  * @author Marek Buch
  *
  * @param id of the new enemy 
  * @param enemy_name a string with the name of the new enemy
  * @return a pointer to the enemy if everything goes well or NULL if there was some mistakes
  */
Enemy *enemy_create(Id id, char* enemy_name);

/**
  * @brief It destroys a enemy that was already created
  * @author Marek Buch
  *
  * @param enemy a enemy structure we want to destroy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_destroy(Enemy *enemy);

/**
  * @brief It sets the atributes of a created enemy
  * @author Marek Buch
  *
  * @param id is the identification of the enemy
  * @param name is the name of the enemy
  * @param location is the location of the enemy
  * @param object a boolean, specifying if the enemy has an object (TRUE) or not (FALSE)
  * @return a enemy with set atributes
  */
Enemy *enemy_set(Enemy *enemy, Id id, char *name, Id location, BOOL object);

/**
  * @brief It sets enemys location
  * @author Marek Buch
  *
  * @param enemy where we are getting the enemy from
  * @param id the location where to set the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_location(Enemy *enemy, Id id);

/**
  * @brief It returns enemys location
  * @author Marek Buch
  *
  * @param enemy where we are getting the enemy location from from
  * @return enemys location
  */
Id enemy_get_location(Enemy *enemy);

/**
  * @brief It returns the id of the enemy
  * @author Marek Buch
  *
  * @param enemy a pointer to the enemy
  * @return the id of the enemy
  */
Id enemy_get_id(Enemy *enemy);

/**
  * @brief It sets whether the enemy has an object or not
  * @author Marek Buch
  *
  * @param enemy a pointer to the enemy
  * @param object a boolean, specifying if the enemy has an object (TRUE) or not (FALSE)
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_object(Enemy *enemy, BOOL object);

/**
  * @brief It gets whether the enemy has an object or not
  * @author Marek Buch
  *
  * @param enemy a pointer to the enemy
  * @return a boolean, specifying if in the space there is an object (TRUE) or not (FALSE)
  */
BOOL enemy_get_object(Enemy *enemy);

/**
  * @brief It prints enemy
  * @author Marek Buch
  *
  * @param enemy where we are getting the enemy info from
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_print(Enemy *enemy);

#endif 