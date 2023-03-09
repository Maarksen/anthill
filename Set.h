/*
* @brief it defines the set interface
*
* @file Set.c
* @author Daniel Cabrero
* @Version 1.0
* @date 23-2-2023
*/

#ifndef SET_H
#define SET_H

#include "space.h"

typedef struct _Set Set;

/*
* @brief it allocates memory for a new Set
* and initializes its members
* @author Daniel Cabrero
*
* @param none
* @return an initialized Set
*/
Set *Set_create();

/*
* @brief it frees the memory of a set
* @author Daniel Cabrero
*
* @param set a pointer to the set that must be destroyed
* @return OK if freed correctly, ERROR otherwise
*/
STATUS Set_destroy(Set *set);

/*
*@brief it adds a new Id at the end of the set
*@author Daniel Cabrero
*
*@param set a pointer to the set you want to add an id to
*newId the Id that will be added
*@return OK if added correctly, ERROR otherwhise
*/
STATUS Set_Add(Set *set, Id newId);

/*
*@brief it deletes the last id of the set
*@author Daniel Cabrero
*
*@param set a pointer to the set you wanto to delete the last id from
*@return OK if deleted correctly, ERROR otherwhise
*/
STATUS Set_Del(Set *set);

/*
*@brief it prints a set to be debugged
*@author Daniel Cabrero
*
*@param set the set you want to print
*@return OK if printed correctly, ERROR otherwhise
*/
STATUS Set_print(Set * set);

/*
*@brief it checks if the set is empty
*@author Daniel Cabrero
*
*@param set the set you want to check
*@return TRUE if set is empty, FALSE otherwhise
*/
BOOL Set_isEmpty(Set * set);

/*
*@brief returns the Id of a given position
*@author Daniel Cabrero
*
*@param set the source set where you want to take the Id from
*       pos the position of the Id
*@return the id if it worked correctly, returns -1 otherwise
*/

Id Set_getId(Set * set, int pos);

/*
*@brief inserts an Id at a determined position of a set (it can also be used to delet an Id of a determined position)
*@author Daniel Cabrero
*
*@param set pointer to the source set where you want to insert the Id in
*       pos the position of the Id
*       id the new Id you want to insert
*@return Ok if the id was inserted correctly, ERROR otherwise
*/
STATUS Set_setId(Set * set, int pos, Id id);

/**
* @brief tells the last Id from a set
* @author Daniel Cabrero
*
* @param set pointer to the source set where you want to know the last id from
*       
*@return the last Id of the set, if error returns -1
*/
Id Set_getLastId( Set *set);
#endif