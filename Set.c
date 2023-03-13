/*
* @brief it implements the set module
*
* @file Set.c
* @author Daniel Cabrero
* @Version 1.0
* @date 23-2-2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "Set.h"

/*
* @brief Set
*
* This struct defines a set of entities (objects, players etc.)
*/
struct _Set{
Id * ids;
Id n_ids;
};


Set * Set_create(){
  Set *newSet;

  
  newSet = (Set *) malloc(sizeof (Set));
  if (newSet == NULL) {
    return NULL;
  }

  newSet->ids = (Id*) malloc(MAX_SPACES*sizeof(Id));
  if (newSet->ids == NULL) {
    free(newSet);
    return NULL;
  }

  for (int i = 0; i<MAX_SPACES; i++){
    newSet->ids[i] = 0;
  }
  newSet->n_ids = 0;
  

  return newSet;
}

STATUS Set_destroy(Set *set){
  if (!set) {
    return ERROR;
  }

  free(set->ids);
  free(set);
  set = NULL;
  return OK;
}

STATUS Set_Add(Set *set, Id newId){
if(!set){
  return ERROR;
}
set->ids[set->n_ids]=newId;
set->n_ids++;

return OK;

}

STATUS Set_Del(Set *set){
if(!set){
  return ERROR;
}
set->ids[set->n_ids]=0;
set->n_ids--;
return OK;

}

STATUS Set_print(Set * set){
int i=0;
if (!set){
  return ERROR;
}

while(set->ids[i] !='\0'){
  printf(" id number %d: %ld",(i+1),set->ids[i]);
  i++;
}
if(i!=set->n_ids){
  return ERROR;
}
  return OK;
}

BOOL Set_isEmpty(Set * set){
  if (!set){
    return TRUE;
  }else if(set->n_ids < 1){
    return TRUE;
  }
  return FALSE;

}

Id Set_getId(Set * set, int pos){
  if(!set||pos<0){
    return -1;
  }

  return set->ids[pos];
}

STATUS Set_setId(Set * set, int pos, Id id){
if(!set||pos<0||id<0){
  return ERROR;
}
set->ids[pos]=id;
return OK;
}

Id Set_getLastId(Set * set){
  if(!set){
    return -1;
  }
  return set->ids[set->n_ids-1];
}


