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
  * @author Ignacio Martin
  * 
  * @param id the identification number for the new object
  * @return a new object, initialized
  */
Object* object_create(Id id);

/**
  * @brief It destroys an object, freeing the allocated memory
  * @author Ignacio Martin
  * 
  * @param object a pointer to the object that must be destroyed
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object* object);

/**
  * @brief It sets the id of an object
  * @author Ignacio Martin
  * 
  * @param object a pointer to the object
  * @param id the identification number for object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_set_id(Object* object, Id id);

/**
  * @brief It gets the id of an object
  * @author Ignacio Martin
  * 
  * @param object a pointer to the object
  * @return the id of the object
  */
Id object_get_id(Object* object);

/**
  * @brief It sets the location of an object
  * @author Ignacio Martin
  * 
  * @param object a pointer to the object
  * @param location the identification number for the object location
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_set_location(Object* object, Id id);

/**
  * @brief It gets the location of an object
  * @author Ignacio Martin
  * 
  * @param object a pointer to the object
  * @return the location of the object
  */
Id object_get_location(Object* object);

/**
  * @brief It sets the name of an object
  * @author Ignacio Martin
  * 
  * @param object a pointer to the object
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_set_name(Object* object, char* name);

/**
  * @brief It gets the name of an object
  * @author Ignacio Martin
  * 
  * @param object a pointer to the object
  * @return a string with the name of the object
  */
const char * object_get_name(Object* object);

/**
  * @brief It prints the object information
  * @author Ignacio Martin
  * 
  * @param object a pointer to the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(Object* object);

#endif