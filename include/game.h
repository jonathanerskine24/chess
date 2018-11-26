#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/piece.h"
#include "../include/board.h"


struct position;
class Piece;
class Board;
class Tile;

class Game {
	private:
		Board *board;
		void setMenu(bool);
		bool getMenu();
		bool whiteTurn;
		bool blackTurn;
		void pieceClickCheck(position, Piece*);
		bool tileClickCheck(position, Tile*);
		bool isRunning;
		bool isBegan;
		bool pieceSelected;
		Tile* selectedTile;
		Piece* selectedPiece;
		SDL_Window *window;
		SDL_Renderer *renderer;
		bool checkCollision(SDL_Rect a, SDL_Rect b);
		bool checkValidMove(Piece*, Tile*);
	public:
		Game();
		~Game();
		void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
		void handleEvents();
		void update();
		void render();
		void clean();
		bool running();
		bool began();
		void renderMenu();
		void Reset();
		// SDL_Renderer* getRenderer();

};