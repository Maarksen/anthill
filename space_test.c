/**
 * @brief It loads the game from a file
 *
 * @file space_test.c
 * @author Marek Buch
 * @version 1.0
 * @date 09-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <string.h>
#include "space.h"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

void space_testing(){
    Space *space = space_create(10);
    Space *space1 = space_create(11);

    if(space != NULL && space1 != NULL){
        printf("%s[SUCCESS] space_create successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_create failed\n", KRED);
    }

    if(space_get_id(space) == 10 && space_get_id(space1) == 11){
        printf("%s[SUCCESS] space_get_id successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_get_id failed\n", KRED);
    }

    space_set_name(space, "space");
    space_set_name(space1, "space1");
    if(strcmp(space_get_name(space),"space") == 0 && strcmp(space_get_name(space1), "space1") == 0){
        printf("%s[SUCCESS] space_set_name successful\n", KGRN);
        printf("%s[SUCCESS] space_get_name successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_set_name failed\n", KRED);
        printf("%s[FAIL] space_get_name failed\n", KRED);
    }

    space_set_north(space, 100);
    space_set_north(space1, 101);
    if(space_get_north(space) == 100 && space_get_north(space1)){
        printf("%s[SUCCESS] space_set_north successful\n", KGRN);
        printf("%s[SUCCESS] space_get_north successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_set_north failed\n", KRED);
        printf("%s[FAIL] space_get_north failed\n", KRED);
    }

    space_set_south(space, 100);
    space_set_south(space1, 101);
    if(space_get_south(space) == 100 && space_get_south(space1)){
        printf("%s[SUCCESS] space_set_south successful\n", KGRN);
        printf("%s[SUCCESS] space_get_south successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_set_south failed\n", KRED);
        printf("%s[FAIL] space_get_south failed\n", KRED);
    }

    space_set_west(space, 100);
    space_set_west(space1, 101);
    if(space_get_west(space) == 100 && space_get_west(space1)){
        printf("%s[SUCCESS] space_set_west successful\n", KGRN);
        printf("%s[SUCCESS] space_get_west successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_set_west failed\n", KRED);
        printf("%s[FAIL] space_get_west failed\n", KRED);
    }

    space_set_east(space, 100);
    space_set_east(space1, 101);
    if(space_get_east(space) == 100 && space_get_east(space1)){
        printf("%s[SUCCESS] space_set_east successful\n", KGRN);
        printf("%s[SUCCESS] space_get_east successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_set_east failed\n", KRED);
        printf("%s[FAIL] space_get_east failed\n", KRED);
    }

    char *new_gdesc[10] = {"---------", "000000000", "000000000", "111111111", "444444444"};
    space_set_gdesc(space, new_gdesc);
    space_set_gdesc(space1, new_gdesc);

    const char **test_gdesc = space_get_gdesc(space);
    const char **test_gdesc1 = space_get_gdesc(space1);
    BOOL is_okay = FALSE;
    for(int i = 0; i < 5; i++){
        if(strcmp(test_gdesc[i], new_gdesc[i]) != 0){
            is_okay = TRUE;
        }
        if(strcmp(test_gdesc1[i], new_gdesc[i]) != 0){
            is_okay = TRUE;
        }
    }

    if(!is_okay){
        printf("%s[SUCCESS] space_set_gdesc successful\n", KGRN);
        printf("%s[SUCCESS] space_get_gdesc successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_set_gdesc failed\n", KRED);
        printf("%s[FAIL] space_get_gdesc failed\n", KRED);
    }

    space_set_object(space, 01);
    space_set_north(space1, 02);
    if(space_get_object(space, 01) != NULL && space_get_object(space1, 02) != NULL){
        printf("%s[SUCCESS] space_set_object successful\n", KGRN);
        printf("%s[SUCCESS] space_get_object successful\n", KGRN);
    }
    else{
        printf("%s[FAIL] space_set_object failed\n", KRED);
        printf("%s[FAIL] space_get_object failed\n", KRED);
    }

    space_destroy(space);
    space_destroy(space1);
    printf("%s[SUCCESS] space_destroy successful\n", KGRN);
}

int main(){
    space_testing();
    return 0;
}