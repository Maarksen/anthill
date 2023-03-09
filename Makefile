CC = gcc -pedantic
CFLAGS = -Wall
EXE = anthill
LIB = -lscreen -L .

all : $(EXE) clear

clear :
	rm -rf *.o

clean :
	rm -rf *.o anthill

$(EXE) : % : command.o enemy.o game_loader.o game_loop.o game_reader.o game.o graphic_engine.o object.o player.o space.o enemy_test.o space_test.o
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -o $@ command.o enemy.o game_loader.o game_loop.o game_reader.o game.o graphic_engine.o object.o player.o space.o enemy_test.o space_test.o $(LIB) 

command.o : command.c command.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

enemy.o : enemy.c enemy.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

enemy_test.o : enemy_test.c enemy_test.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

game_loader.o : game_loader.c game_loader.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

game_loop.o : game_loop.c
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

 game_reader.o : game_reader.c game_reader.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

 game.o : game.c game.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

graphic_engine.o : graphic_engine.c graphic_engine.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

object.o : object.c object.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

player.o : player.c player.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

space.o : space.c space.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

space_test.o : space_test.c space_test.h
	@echo "#---------------------------"
	@echo "# Generating $@"
	@echo "# Depends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<
