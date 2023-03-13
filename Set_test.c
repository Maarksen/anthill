/**
 * @brief It loads the game from a file
 *
 * @file Set_test.c
 * @author Daniel Cabrero
 * @version 1.0
 * @date 09-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <string.h>
#include "Set.h"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

void Set_testing(){
    Set *set = Set_create();
    Set *set2 = Set_create(11);

    if(set != NULL && set2 != NULL){
        printf("%s[SUCCESS] Set_create successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] Set_create failed\n", KRED);
    }

    if(Set_Add(set, 1) && Set_Add(set2, 2)){
        printf("%s[SUCCESS] Set_Add successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] Set_Add failed\n", KRED);
    }

    if(Set_Del(set)){
        printf("%s[SUCCESS] Set_Del successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] Set_Del failed\n", KRED);
    }

    if(Set_isEmpty(set) && !Set_isEmpty(set2)){
        printf("%s[SUCCESS] Set_isEmpty successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] Set_isEmpty failed\n", KRED);
    }

    if(Set_getId(set2, 0) == 2){
        printf("%s[SUCCESS] Set_getId successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] Set_getId failed\n", KRED);
    }

    if(Set_setId(set2, 0, 5)){
        printf("%s[SUCCESS] Set_setID successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] Set_setID failed\n", KRED);
    }

    if(Set_getLastId(set2) == 5){
        printf("%s[SUCCESS] Set_getLastId successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] Set_getLastId failed\n", KRED);
    }

    if(Set_destroy(set) && Set_destroy(set2)){
        printf("%s[SUCCESS] Set_destroy successful\n", KGRN);
    }
}

int main(){
    Set_testing();
    return 0;
}