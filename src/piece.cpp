#include "../include/piece.h"

Piece::Piece(int TYPE, bool TEAM, const char* textureLocation, SDL_Renderer* ren, int x, int y) {
	type = TYPE;
	team = TEAM;
	ren = ren;
	setLocation(x, y);
	pieceRect.w = 100;
	pieceRect.h = 100;
	pos.x = x / 100;
	pos.y = y / 100;
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
	if (c) clicked = true;
	else clicked = false;
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

position* Piece::getPos() {
	return &pos;
}

void Piece::setPos(int x, int y) {
	pos.x = x;
	pos.y = y;
}

bool Piece::getTeam() {
	return team;
}