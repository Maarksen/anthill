#include "game_reader.h"


STATUS game_create_from_file(Game *game, char *filename) {
    if (game_create(game) == ERROR) {
        return ERROR;
    }

    if (game_load_spaces(game, filename) == ERROR) {
        return ERROR;
    }

    if (game_load_objects(game, filename) == ERROR) {
        return ERROR;
    }

    /* The player and the object are located in the first space */
    game_set_player_location(game, game_get_space_id_at(game, 0));

    return OK;
}

STATUS game_load_spaces(Game *game, char *filename) {
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
    Space *space = NULL;
    STATUS status = OK;

    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#s:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            north = atol(toks);
            toks = strtok(NULL, "|");
            east = atol(toks);
            toks = strtok(NULL, "|");
            south = atol(toks);
            toks = strtok(NULL, "|");
            west = atol(toks);
#ifdef DEBUG
            printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
            space = space_create(id);
            if (space != NULL) {
                space_set_name(space, name);
                space_set_north(space, north);
                space_set_east(space, east);
                space_set_south(space, south);
                space_set_west(space, west);
                game_add_space(game, space);
            }
        }
    }

    if (ferror(file)) {
        status = ERROR;
    }

    fclose(file);

    return status;
}

STATUS game_load_objects(Game *game, char *filename) {
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, location = NO_ID;
    Object *object = NULL;
    STATUS status = OK;

    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#o:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            location = atol(toks);
#ifdef DEBUG
            printf("Leido: %ld|%s|%ld\n", id, name, location);
#endif
            object = object_create(id);
            if (object != NULL) {
                object_set_location(object, location);
                object_set_id(object, id);
                game_add_object(game, object);
            }
        }
    }

    if (ferror(file)) {
        status = ERROR;
    }

    fclose(file);

    return status;
}

STATUS game_add_space(Game *game, Space *space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL) {
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

STATUS game_add_object(Game *game, Object *object) {
  int i = 0;

  if (object == NULL) {
    return ERROR;
  }

  while (i < MAX_SPACES && game->objects[i] != NULL) {
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->objects[i] = object;

  return OK;
}

STATUS game_set_object_location(Game *game, Id id, int pos) {
  if (id == NO_ID) {
    return ERROR;
  }
  
  object_set_location(game->objects[pos], id);
  space_set_object(game_get_space(game, id), TRUE);
  return OK;
}

/** It gets the location the player
  */
Id game_get_player_location(Game *game) {
  return player_get_location(game->player);
}

/** It gets the location the object
  */
Id game_get_object_location(Game *game, int pos) {
  return object_get_location(game->objects[pos]);
}


Space *game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}

Id game_get_space_id_at(Game *game, int position) {
  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

STATUS game_set_player_location(Game *game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;
}

Object *game_get_object(Game *game, int i){
  return game->objects[i];
}