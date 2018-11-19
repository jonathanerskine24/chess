#include "../include/piece.h"

Piece::Piece(int TYPE, bool team, const char* textureLocation, SDL_Renderer* ren, int x, int y) {
	type = TYPE;
	team = team;
	ren = ren;
	setLocation(x, y);
	pieceRect.w = 100;
	pieceRect.h = 100;
	// pieceRect.x = 1/00;
	// pieceRect.y = 100;
	pieceTex = TextureManager::LoadTexture(textureLocation, ren);
}

SDL_Texture* Piece::getTexture() {
	return pieceTex;
}

SDL_Rect* Piece::getRect() {
	return &pieceRect;
}

void Piece::setClicked(bool c) {
	if (c) clicked == true;
	else clicked == false;
	return;
}

bool Piece::getClicked() {
	return clicked;
}

int Piece::getType() {
	return type;
}

void Piece::setLocation(int x, int y) {
	pieceRect.x = x;
	pieceRect.y = y;
	return;
}