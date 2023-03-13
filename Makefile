CC = gcc -pedantic
CFLAGS = -Wall
EXE = anthill
LIB = -lscreen -L .
OBJ = command.o enemy.o game_loop.o game_reader.o game.o graphic_engine.o object.o player.o space.o Set.o

all : $(EXE) clear

clear :
	rm -rf *.o

clean :
	rm -rf *.o anthill enemy_test space_test Set_test

$(EXE) : % : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB) 

command.o : command.c command.h
	$(CC) $(CFLAGS) -c $<

enemy.o : enemy.c enemy.h
	$(CC) $(CFLAGS) -c $<

game_loop.o : game_loop.c
	$(CC) $(CFLAGS) -c $<

 game_reader.o : game_reader.c game_reader.h
	$(CC) $(CFLAGS) -c $<

 game.o : game.c game.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o : graphic_engine.c graphic_engine.h
	$(CC) $(CFLAGS) -c $<

object.o : object.c object.h
	$(CC) $(CFLAGS) -c $<

player.o : player.c player.h
	$(CC) $(CFLAGS) -c $<

space.o : space.c space.h
	$(CC) $(CFLAGS) -c $<

Set.o : Set.c Set.h
	$(CC) $(CFLAGS) -c $<

space_test.o : space_test.c space_test.h
	$(CC) $(CFLAGS) -c $<

space_test : space_test.o space.o Set.o object.o
	$(CC) $(CFLAGS) -o $@ space_test.o space.o Set.o object.o
	rm -rf *.o

enemy_test.o : enemy_test.c enemy_test.h
	$(CC) $(CFLAGS) -c $<

enemy_test : enemy_test.o enemy.o Set.o
	$(CC) $(CFLAGS) -o $@ enemy_test.o enemy.o Set.o
	rm -rf *.o

Set_test.o : Set_test.c Set_test.h
	$(CC) $(CFLAGS) -c $<

Set_test : Set_test.o Set.o
	$(CC) $(CFLAGS) -o $@ Set_test.o Set.o
	rm -rf *.o