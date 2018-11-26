#pragma once
#include <SDL2/SDL.h>
#include "../include/piece.h"
#include <vector>



struct position;
class Piece;



class Tile {
private:
	SDL_Rect tileRect;
	Piece *piece;
	bool open;
	char x_coord;
	char y_coord;
	position *pos;
	bool clicked;
public:
	Tile(int, int, int, int);
	~Tile();
	SDL_Rect* getRect();
	void setClicked(bool);
	bool getClicked();
	void setOpen(bool);
	bool getOpen();
	char getTileX();
	char getTileY();
	int getX();
	int getY();
	position* getPos();
	Piece* getPiece();
	void setPiece(Piece*);
};


class Board {
private:
	std::vector<Piece*> pieces;
	Tile* tileArray[8][8];
public:
	void printBoardOpenDiagram();
	Board(SDL_Renderer*);
	~Board();
	std::vector<Piece*> getPiecesVector();
	Tile* getTile(int, int);
};


