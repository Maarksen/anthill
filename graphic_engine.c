/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"
#include "game_reader.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"

#define ROWS 29
#define COLUMNS 80

struct _Graphic_engine {
  Area *map, *descript, *banner, *help, *feedback;
};

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge) {
    return ge;
  }

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL) {
    return NULL;
  }

  ge->map = screen_area_init( 1, 1, 48, 19);
  ge->descript = screen_area_init(50, 1, 29, 19);
  ge->banner = screen_area_init(28,21, 23,  1);
  ge->help = screen_area_init( 1,22, 78,  2);
  ge->feedback = screen_area_init( 1,25, 78,  3);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  int i,j;
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_left = NO_ID, id_right = NO_ID;
  Space* space_act = NULL;
  char ob1[50],ob2[50],ob3[50],ob4[50];
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);

    strcpy(ob1,"  ");  /*Inicialmente no hay nada en o1*/
    strcpy(ob2,"  ");  /*Inicialmente no hay nada en o2*/
    strcpy(ob3,"  ");  /*Inicialmente no hay nada en o3*/
    strcpy(ob4,"  ");  /*Inicialmente no hay nada en o4*/

    for(i=0;i<MAX_OBJ;i++){
      if(game_get_object_location(game,object_get_id(game_get_object(game,i)))==id_back){   /*Comprueba que la localización del objeto sea la misma que id_back*/
        if(i==0){
          sprintf(ob1, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==1){
          sprintf(ob2, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==2){
          sprintf(ob3, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==3){
          sprintf(ob4, "%2ld", object_get_id(game_get_object(game,i)));
        }
      }
    }


    if (id_back!=NO_ID) {
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map,str);
      sprintf(str, "  |              %3d|",(int) id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_back),0));  
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_back),1));  
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_back),2));   
      screen_area_puts(ge->map, str);
      printf(str, "   |%s %s %s %s      |",ob1,ob2,ob3,ob4);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "          ^");
      screen_area_puts(ge->map, str);
    }



    strcpy(ob1,"  ");  
    strcpy(ob2,"  ");  
    strcpy(ob3,"  ");
    strcpy(ob4,"  ");

    for(i=0;i<MAX_OBJ;i++){
      if(game_get_object_location(game,object_get_id(game_get_object(game,i)))==id_act){   
        if(i==0){
          sprintf(ob1, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==1){
          sprintf(ob2, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==2){
          sprintf(ob3, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==3){
          sprintf(ob4, "%2ld", object_get_id(game_get_object(game,i)));
        }
      }
    }


    if (id_act!=NO_ID) {
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |m0^           %3d|",(int) id_act);
      screen_area_puts(ge->map,str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_act),0));    
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_act),1));    
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_act),2));

      id_right = space_get_west(space_act);
      id_left = space_get_east(space_act); 
      if (id_right != NO_ID && id_left != NO_ID) {
        screen_area_puts(ge->map, str);
        sprintf(str, " <|                 |>");
      } else if (id_left != NO_ID) {
        screen_area_puts(ge->map, str);
        sprintf(str, " <|                 |");
      } else if (id_right != NO_ID) {
        screen_area_puts(ge->map, str);
        sprintf(str, "  |                 |>");
      } else {
        screen_area_puts(ge->map, str);
        sprintf(str, "  |                 |");
      }
      
      screen_area_puts(ge->map,str);
      sprintf(str, "  |%s %s %s %s      |",ob1,ob2,ob3,ob4);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map, str);

    }



    strcpy(ob1,"  "); 
    strcpy(ob2,"  ");  
    strcpy(ob3,"  ");  
    strcpy(ob4,"  ");  

    for(i=0;i<MAX_OBJ;i++){
      if(game_get_object_location(game,object_get_id(game_get_object(game,i)))==id_next){  
        if(i==0){
          sprintf(ob1, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==1){
          sprintf(ob2, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==2){
          sprintf(ob3, "%2ld", object_get_id(game_get_object(game,i)));
        }
        if(i==3){
          sprintf(ob4, "%2ld", object_get_id(game_get_object(game,i)));
        }
      }
    }


    if (id_next!=NO_ID) {
      sprintf(str, "          v");
      screen_area_puts(ge->map,str);
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map,str);
      sprintf(str, "  |              %3d|",(int) id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_next),0));   
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_next),1)); 
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |",space_get_gdesc(game_get_space(game,id_next),2)); 
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s %s %s %s      |",ob1,ob2,ob3,ob4);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map, str);

    }

  }




  /* Paint the in the description area */
  screen_area_clear(ge->descript);
  sprintf(str, "  Objects location:");   
  screen_area_puts(ge->descript, str);
  for(j=0;j<MAX_OBJ;j++){
    if(game_get_object_location(game,object_get_id(game_get_object(game,j)))!=NO_ID){  
      sprintf(str, "  O%ld:%ld",object_get_id(game_get_object(game,j)),game_get_object_location(game,object_get_id(game_get_object(game,j))));
      screen_area_puts(ge->descript, str);
    }
  }

  sprintf(str,"     ");
  screen_area_puts(ge->descript, str);

  if(player_get_object(game->player)!=NO_ID){  /*player lleva un objeto*/
    sprintf(str,"  Player object: O%d",player_get_object(game->player)!=NO_ID);
    screen_area_puts(ge->descript, str);
  }else{
    sprintf(str, "  Player object: no object ");  /*player no lleva objeto*/
    screen_area_puts(ge->descript, str);
  }

  sprintf(str,"     ");
  screen_area_puts(ge->descript, str);

 /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, left or l, right or r, take or t, drop or d,            attack or a, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  if(last_cmd == NO_CMD || last_cmd == UNKNOWN) {
    sprintf(str, " -%s (%s): ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  } else {
    sprintf(str, " -%s (%s): OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  }

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");

}
