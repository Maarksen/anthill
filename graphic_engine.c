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
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"

#define ROWS 50
#define COLUMNS 92

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

  ge->map = screen_area_init(1, 1, 60, 40);
  ge->descript = screen_area_init(62, 1, 29, 40);
  ge->banner = screen_area_init(33, 42, 23, 1);
  ge->help = screen_area_init(1, 43, 90, 2);
  ge->feedback = screen_area_init(1, 46, 90, 3);

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

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_left = NO_ID, id_right = NO_ID;
  Id obj_loc = NO_ID, ply_loc = NO_ID, ene_loc = NO_ID;
  Space *space_act = NULL;
  int player_hp, enemy_hp;
  char obj = '\0', ene = '\0';
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  player_hp = player_get_hp(game->player);
  enemy_hp = enemy_get_hp(game->enemy);

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_left = space_get_east(space_act);
    id_right = space_get_west(space_act);

    if (game_get_object_location(game) == id_back)
      obj = '*';
    else
      obj = ' ';

    if (enemy_get_location(game->enemy) == id_back && enemy_hp > 0)
      ene = 'e';
    else
      ene = ' ';

    if (id_back != NO_ID) {
      sprintf(str, "  |         %2d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", ene);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game) == id_act)
      obj = '*';
    else
      obj = ' ';

    if (enemy_get_location(game->enemy) == id_act && enemy_hp > 0)
      ene = 'e';
    else
      ene = ' ';

    if (id_act != NO_ID) {
      if (id_left != NO_ID && id_right != NO_ID) {
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  | m0^     %2d|", (int)id_act);
        sprintf(str, "  |     %c     |", ene);
        screen_area_puts(ge->map, str);
        screen_area_puts(ge->map, str);
        sprintf(str, "<<|     %c     |>>", obj);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
      } else if (id_left != NO_ID) {
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  | m0^     %2d|", (int)id_act);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |     %c     |", ene);
        screen_area_puts(ge->map, str);
        sprintf(str, "<<|     %c     |", obj);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
      } else if (id_right != NO_ID){
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  | m0^     %2d|", (int)id_act);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |     %c     |", ene);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |     %c     |>>", obj);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
      } else {
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  | m0^     %2d|", (int)id_act);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |     %c     |", ene);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |     %c     |", obj);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
      }
    }

    if (game_get_object_location(game) == id_next)
      obj = '*';
    else
      obj = ' ';
    
    if (enemy_get_location(game->enemy) == id_next && enemy_hp > 0)
      ene = 'e';
    else
      ene = ' ';

    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", ene);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  if ((obj_loc = game_get_object_location(game)) != NO_ID) {
    sprintf(str, "  Object location:%d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }

  if ((ply_loc = game_get_player_location(game)) != NO_ID) {
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  Player location:%d", (int)ply_loc);
    screen_area_puts(ge->descript, str);

    sprintf(str, "  Player health:%d", player_hp);
    screen_area_puts(ge->descript, str);
  }

  if ((ene_loc = enemy_get_location(game->enemy)) != NO_ID) {
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  Enemy location:%d", (int)ene_loc);
    screen_area_puts(ge->descript, str);

    sprintf(str, "  Enemy health:%d", enemy_hp);
    screen_area_puts(ge->descript, str);
  }


  /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, left or l, right or r, take or t, drop or d, attack or a,           exit or e");
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
