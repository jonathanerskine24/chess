#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include "../include/TextureManager.h"


/*
 0 = pawn
 1 = rook
 2 = knight
 3 = bishop
 4 = queen
 5 = king
*/


struct position {
	int x;
	int y;
};

class Piece {
	private:
		SDL_Texture *pieceTex;
		position pos;
		SDL_Rect pieceRect;
		bool team; // 1 = black, 0 = white
		bool clicked;
		int type; 
		SDL_Renderer *ren;
	public:
		Piece(int, bool, const char*, SDL_Renderer*, int, int);
		~Piece();
		SDL_Texture* getTexture();
		SDL_Rect* getRect();
		void setClicked(bool);
		bool getClicked();
		int getType();
		bool getTeam();
		position* getPos();
		void setPos(int, int);
		void setLocation(int, int);
};
