/** 
 * @brief It implements the space module
 * 
 * @file space.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "Set.h"

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  char *gdesc[10];             /*!< Array of strings*/
  Id north;                 /*!< Id of the space at the north */
  Id south;                 /*!< Id of the space at the south */
  Id east;                  /*!< Id of the space at the east */
  Id west;                  /*!< Id of the space at the west */
  Set * objects;            /*!< the set of objects the space has */
};

/** space_create allocates memory for a new space
  *  and initializes its members
  */
Space* space_create(Id id) {
  Space *newSpace = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));
  if (newSpace == NULL) {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  for(int i = 0; i < 5; i++){
      newSpace->gdesc[i] = "         ";
  }
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->objects = Set_create();

  return newSpace;
}

/** space_destroy frees the previous memory allocation 
  *  for a space
  */
STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }
  Set_destroy(space->objects);
  free(space);
  space = NULL;
  return OK;
}

/** It gets the id of a space
  */
Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

/** It sets the name of a space
  */
STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }
  return OK;
}

/** It gets the name of a space
  */
const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

/** It sets the id of the space located at the north
  */
STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}
/** It gets the id of the space located at the north
  */
Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

/** It sets the id of the space located at the south
  */
STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}
/** It gets the id of the space located at the south
  */
Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

/** It sets the id of the space located at the east
  */
STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

/** It gets the id of the space located at the east
  */
Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

/** It sets the id of the space located at the west
  */
STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}
/** It gets the id of the space located at the west
  */
Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

/** It sets whether the space has an object or not
  */
STATUS space_set_object(Space* space, Id newId) {
  if (!space) {
    return ERROR;
  }
  set_Add(space->objects,newid);
  return OK;
}
/** It gets whether the space has an object or not
  */
Id space_get_object(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return et_getId(space->objects, Set_getLastId(space->objects));;
}
/** It tells if a determined Id is in the space
  */
BOOL space_contains_id(Space* space, Id id){
    int i=0;
    if(!space||id<0){
        return FALSE;
    }
    while(Set_getId(space->objects, i)!='\0'){
        if(Set_getId(space->objects, i)==id){
            return TRUE;
        }
        i++;
    }
    return FALSE;
}

/** It sets the gdesc field of a space
  */
STATUS space_set_gdesc(Space *space, char **new_gdesc){
    if(!space){
        return ERROR;
    }
    else {
        for(int i = 0; i < 5; i++){
            strcpy(space->gdesc[i], new_gdesc[i]);
        }
        return OK;
    }
}

/** It returns the gdesc field of a space
  */
const char ** space_get_gdesc(Space *space){
    if(!space){
        return NULL;
    }
    else{
        return (const char **) space->gdesc;
    }
}
/** It sets whether the space has an object or not
  */
STATUS space_set_object_at(Space* space, Id newid , int pos) {
  if (!space||pos<0) {
    return ERROR;
  }
  if(pos==0){
      if(space_set_object(space,newid)==ERROR){
          return ERROR;
      }else{
          return OK;
      }
  }
  if(Set_setId(space->objects, pos, newid)==ERROR){
      return ERROR;
  }
  return OK;
}
/** It gets the object´s Id from a determined position
  */
Id space_get_object_at(Space* space, int pos) {
  if (!space||Set_getId(space->objects, pos)==NULL) {
    return -1;
  }
  return Set_getId(space->objects, pos);
}


/** It prints the space information
  */
STATUS space_print(Space* space) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!space) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
 
  /* 2. For each direction, print its link */ 
  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  /* 3. Print if there is an object in the space or not */
  if (space_get_object(space)) {
    fprintf(stdout, "---> Object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  return OK;
}

