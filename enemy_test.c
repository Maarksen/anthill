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
#include "enemy_test.h"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

void enemy_testing(){
    Enemy *enemy = enemy_create(10, "yes");
    Enemy *enemy1 = enemy_create(11, "yesyes");
    if(enemy != NULL && enemy1 != NULL){
        printf("%s[SUCCESS] enemy_create successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_create failed\n", KRED);
    }

    enemy_set(enemy, 1, "no", 144, 50);
    enemy_set(enemy1, 2, "nono", 145, 51);
    if((enemy_get_id(enemy) == 1 && enemy_get_location(enemy) == 144 && enemy_get_hp(enemy) == 50) &&
    (enemy_get_id(enemy1) == 2 && enemy_get_location(enemy1) == 145 && enemy_get_hp(enemy1) == 51)){
        printf("%s[SUCCESS] enemy_set successful\n", KGRN);
        printf("%s[SUCCESS] enemy_get_id successful\n", KGRN);
        printf("%s[SUCCESS] enemy_get_location successful\n", KGRN);
        printf("%s[SUCCESS] enemy_get_hp successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_set failed\n", KRED);
        if(enemy_get_id(enemy) != 1 || enemy_get_id(enemy1) != 2) {
            printf("%s[FAIL] enemy_get_id failed\n", KRED);
        }
        if(enemy_get_location(enemy) != 144 || enemy_get_location(enemy1) != 145) {
            printf("%s[FAIL] enemy_get_location failed\n", KRED);
        }
        if(enemy_get_hp(enemy) != 50 || enemy_get_hp(enemy1) != 51) {
            printf("%s[FAIL] enemy_get_hp failed\n", KRED);
        }
    }

    enemy_set_location(enemy, 155);
    enemy_set_location(enemy1, 156);
    if(enemy_get_location(enemy) == 155 && enemy_get_location(enemy1) == 156){
        printf("%s[SUCCESS] enemy_set_location successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_set_location failed\n", KRED);
    }

    enemy_set_hp(enemy, 55);
    enemy_set_hp(enemy1, 56);
    if(enemy_get_hp(enemy) == 55 && enemy_get_hp(enemy1) == 56){
        printf("%s[SUCCESS] enemy_set_hp successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] enemy_set_hp failed\n", KRED);
    }

    enemy_destroy(enemy);
    enemy_destroy(enemy1);
    printf("%s[SUCCESS] enemy_destroy successful\n", KGRN);

}


