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

STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

STATUS object_set_id(Object* object, Id id) {
  if (!object || id < 0) {
    return ERROR;
  }
  object->id = id;

  return OK;
}

Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

/** It sets the name of an object
  */
STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }
  return OK;
}

/** It gets the name of an object
  */
const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}

STATUS object_print(Object* object) {

  /* Error Control */
  if (!object) {
    return ERROR;
  }

  /* Print the id and the name of the space */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
 
  return OK;
}