/** 
 * @brief It implements the object module
 * 
 * @file object.c
 * @author Ignacio Martin
 * @version 1.0
 * @date 06-02-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/**
 * @brief Object
 *
 * This struct stores all the information of an object.
 */
struct _Object {
  Id id;            /*!< Id number of the object, it must be unique */
  char *name;       /*!< Name of the object */
};

/** object_create allocates memory for a new object
  *  and initializes its members
  */
Object* object_create(Id id) {
  Object *newObject = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));
  if (newObject == NULL) {
    return NULL;
  }

  /* Initialization of an empty object*/
  newObject->id = id;
  newObject->name = "object";
  
  return newObject;
}

/** object_destroy frees the previous memory allocation 
  *  for an object
  */
STATUS object_destroy(Object* object) {
  /* Error control */
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

/** It sets the id of the object
  */
STATUS object_set_id(Object* object, Id id) {
  /* Error control */
  if (!object || id == NO_ID) {
    return ERROR;
  }
  object->id = id;

  return OK;
}

/** It gets the id of the object
  */
Id object_get_id(Object* object) {
  /* Error control */
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

/** It sets the name of the object
  */
STATUS object_set_name(Object* object, char* name) {
  /* Error control */
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }
  return OK;
}

/** It gets the name of the object
  */
const char * object_get_name(Object* object) {
  /* Error control */
  if (!object) {
    return NULL;
  }
  return object->name;
}

/** It prints the properties of the object
  */
STATUS object_print(Object* object) {

  /* Error Control */
  if (!object) {
    return ERROR;
  }

  /* Print the id and the name of the space */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
 
  return OK;
}