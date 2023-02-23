/**
 * @brief It loads the game from a file
 *
 * @file enemy.c
 * @author Marek Buch
 * @version 1.0
 * @date 09-02-2023
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "enemy.h"

/**
 * @brief Enemy
 *
 * This struct stores all the information of a enemy.
 */
struct _Enemy{
    Id id;          /*!< Id number of the enemy, it must be unique */
    char *name;     /*!< String with the name of the enemy */
    Id location;    /*!< Id number of the space where the enemy is*/
    BOOL object;    /*!< Whether the enemy has an object or not */
};

/** enemy_create allocates memory for a new enemy
  *  and initializes its members
  */
Enemy* enemy_create(Id id, char* enemy_name){
    Enemy *new_enemy = NULL;

    /* Error Control */
    if(id == NO_ID){
        return NULL;
    }

    new_enemy = malloc(sizeof(Enemy));

    /* Error Control */
    if(new_enemy == NULL){
        return NULL;
    }

    /* Initialization of a new enemy */
    new_enemy->id = id;
    new_enemy->name = enemy_name;
    new_enemy->location = NO_ID;

    return new_enemy;
}

/** space_destroy frees the previous memory allocation 
  *  for a enemy
  */
STATUS enemy_destroy(Enemy *enemy){
    /* Error Control */
    if (!enemy) {
        return ERROR;
    }

    free(enemy);
    enemy = NULL;
    return OK;
}

/** It sets the properties of a enemy
  */
Enemy *enemy_set(Enemy *enemy, Id id, char *name, Id location, BOOL object){
    /* Error Control */
    if(enemy == NULL){
        return NULL;
    }
    /* Sets all the properties */
    enemy->id = id;
    enemy->name = name;
    enemy->location = location;
    enemy->object = object;

    return enemy;
}

/** It sets the location of a enemy
  */
STATUS enemy_set_location(Enemy *enemy, Id id){
    if(enemy != NULL) {
        enemy->location = id;
        return OK;
    }
    return ERROR;
}

/** It gets the location of a enemy
  */
Id enemy_get_location(Enemy *enemy){
    if(enemy != NULL) {
        return enemy->location;
    }
    return NO_ID;
}

/** It gets the id of a enemy
  */
Id enemy_get_id(Enemy *enemy){
    if(enemy != NULL) {
        return enemy->id;
    }
    return NO_ID;
}

/** It sets whether the enemy has an object or not
  */
STATUS enemy_set_object(Enemy *enemy, BOOL object){
    if(enemy != NULL) {
        enemy->object = object;
        return OK;
    }
    return ERROR;
}

/** It gets whether the enemy has an object or not
  */
BOOL enemy_get_object(Enemy *enemy){
    if(enemy != NULL) {
        return enemy->object;
    }
    return FALSE;
}

/** It prints the enemy information
  */
STATUS enemy_print(Enemy *enemy){
    /* Error Control */
    if(!enemy){
        return ERROR;
    }

    fprintf(stdout, "enemy (ID: %ld Name: %s Location: %ld :Object: %s)\n", enemy->id, enemy->name, enemy->location, (enemy->object ? "True" : "False"));

    return OK;
}
