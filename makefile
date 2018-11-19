#OBJS specifies which files to compile as part of the project 
OBJS = src/main.cpp src/game.cpp src/TextureManager.cpp src/piece.cpp src/board.cpp
OBJS2 = bin/main.o bin/game.o bin/TextureManager.o bin/piece.o bin/board.o
#CC specifies which compiler we're using 
CC = g++ 
#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
COMPILER_FLAGS = -w 
#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lSDL2 -lSDL2_image 
#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = 01_hello_SDL 
#This is the target that compiles our executable 
all:
	g++ src/main.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	g++ src/game.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	g++ src/board.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	g++ src/piece.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	g++ src/TextureManager.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	make clean
	g++ $(OBJS2) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o chess
	# make clean
	clear
main:
	g++ src/main.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	make clean
	g++ $(OBJS2) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o chess
	clear
game:
	g++ src/game.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	make clean
	g++ $(OBJS2) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o chess
	clear
board:
	g++ src/board.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	make clean
	g++ $(OBJS2) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o chess
	clear
piece:
	g++ src/piece.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	make clean
	g++ $(OBJS2) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o chess
	clear
texturemanager:
	g++ src/TextureManager.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -c
	make clean
	g++ $(OBJS2) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o chess
	clear
build:
	g++ bin/main.o bin/game.o bin/board.o bin/piece.o bin/TextureManager.o -o chess
	make clean
clean:
	cp *.o bin
	rm -rf *.o