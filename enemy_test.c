/**
 * @brief It loads the game from a file
 *
 * @file enemy_test.c
 * @author Marek Buch
 * @version 1.0
 * @date 07-03-2023
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "enemy.h"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

void enemy_testing(){
    Enemy *enemy = enemy_create(10, "yes");
    if(enemy != NULL){
        printf("%s[SUCCESS] enemy_create successful", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_create failed\n", KRED);
    }

    enemy_set(enemy, 1, "no", 144, 50);
    if(enemy_get_id(enemy) == 1 && enemy_get_location(enemy) == 144 && enemy_get_hp(enemy) == 50){
        printf("%s[SUCCESS] enemy_set successful", KGRN);
        printf("%s[SUCCESS] enemy_get_id successful", KGRN);
        printf("%s[SUCCESS] enemy_get_location successful", KGRN);
        printf("%s[SUCCESS] enemy_get_hp successful", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_set failed\n", KRED);
        if(enemy_get_id(enemy) != 1) {
            printf("%s[FAIL] enemy_get_id failed\n", KRED);
        }
        if(enemy_get_location(enemy) != 144) {
            printf("%s[FAIL] enemy_get_location failed\n", KRED);
        }
        if(enemy_get_hp(enemy) != 50) {
            printf("%s[FAIL] enemy_get_hp failed\n", KRED);
        }
    }

    enemy_set_location(enemy, 155);
    if(enemy_get_location(enemy) == 155){
        printf("%s[SUCCESS] enemy_set_location successful", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_set_location failed\n", KRED);
    }

    enemy_set_hp(enemy, 55);
    if(enemy_get_hp(enemy) == 55){
        printf("%s[SUCCESS] enemy_set_hp successful", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_set_hp failed\n", KRED);
    }

    enemy_destroy(enemy);
    if(enemy == NULL){
        printf("%s[SUCCESS] enemy_destroy successful", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_destroy failed\n", KRED);
    }
}


