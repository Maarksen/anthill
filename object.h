/**
 * @brief It defines the object
 *
 * @file object.h
 * @author Ignacio Martin
 * @version 1.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

/**
  * @brief It creates a new object, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new object
  * @return a new space, initialized
  */
Object* object_create(Id id);

/**
  * @brief It creates a new space, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
STATUS object_destroy(Object* object);

/**
  * @brief It creates a new space, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
STATUS object_set_id(Object* object, Id id);

/**
  * @brief It creates a new space, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Id object_get_id(Object* object);

/**
  * @brief It creates a new space, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
STATUS object_set_name(Object* object, char* name);

/**
  * @brief It creates a new space, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
const char * object_get_name(Object* object);

/**
  * @brief It creates a new space, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
STATUS object_print(Object* object);

#endif