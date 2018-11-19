#include "../include/board.h"

Tile::Tile(int x, int y) {
	tileRect.x = x;
	tileRect.y = y;
	tileRect.w = 100;
	tileRect.h = 100;
	free = true;
}


Board::Board(SDL_Renderer *ren) {

	Piece *blackRook1   = new Piece(1, 1, "resources/black/blackRook.png",   ren,   0, 0);	
	Piece *blackKnight1 = new Piece(2, 1, "resources/black/blackKnight.png", ren, 100, 0); //2
	Piece *blackBishop1 = new Piece(3, 1, "resources/black/blackBishop.png", ren, 200, 0);
	Piece *blackQueen   = new Piece(4, 1, "resources/black/blackQueen.png",  ren, 300, 0);
	Piece *blackKing    = new Piece(5, 1, "resources/black/blackKing.png",   ren, 400, 0);
	Piece *blackBishop2 = new Piece(3, 1, "resources/black/blackBishop.png", ren, 500, 0);
	Piece *blackKnight2 = new Piece(2, 1, "resources/black/blackKnight.png", ren, 600, 0);
	Piece *blackRook2   = new Piece(1, 1, "resources/black/blackRook.png",   ren, 700, 0);

	pieces.push_back(blackRook1);
	pieces.push_back(blackKnight1);	
	pieces.push_back(blackBishop1);
	pieces.push_back(blackQueen);
	pieces.push_back(blackKing);
	pieces.push_back(blackRook2);	
	pieces.push_back(blackBishop2);
	pieces.push_back(blackKnight2);

	Piece *blackPawn1 = new Piece(0, 1, "resources/black/blackPawn.png", ren,   0, 100);
	Piece *blackPawn2 = new Piece(0, 1, "resources/black/blackPawn.png", ren, 100, 100);
	Piece *blackPawn3 = new Piece(0, 1, "resources/black/blackPawn.png", ren, 200, 100);
	Piece *blackPawn4 = new Piece(0, 1, "resources/black/blackPawn.png", ren, 300, 100);
	Piece *blackPawn5 = new Piece(0, 1, "resources/black/blackPawn.png", ren, 400, 100);
	Piece *blackPawn6 = new Piece(0, 1, "resources/black/blackPawn.png", ren, 500, 100);
	Piece *blackPawn7 = new Piece(0, 1, "resources/black/blackPawn.png", ren, 600, 100);
	Piece *blackPawn8 = new Piece(0, 1, "resources/black/blackPawn.png", ren, 700, 100);
	
	pieces.push_back(blackPawn1);
	pieces.push_back(blackPawn2);
	pieces.push_back(blackPawn3);
	pieces.push_back(blackPawn4);
	pieces.push_back(blackPawn5);
	pieces.push_back(blackPawn6);
	pieces.push_back(blackPawn7);
	pieces.push_back(blackPawn8);

	Piece *whiteRook1 = new Piece(1, 1, "resources/white/whiteRook.png",     ren,   0, 700);	
	Piece *whiteKnight1 = new Piece(2, 1, "resources/white/whiteKnight.png", ren, 100, 700); //2
	Piece *whiteBishop1 = new Piece(3, 1, "resources/white/whiteBishop.png", ren, 200, 700);
	Piece *whiteQueen = new Piece(4, 1, "resources/white/whiteQueen.png",    ren, 300, 700);
	Piece *whiteKing = new Piece(5, 1, "resources/white/whiteKing.png",      ren, 400, 700);
	Piece *whiteBishop2 = new Piece(3, 1, "resources/white/whiteBishop.png", ren, 500, 700);
	Piece *whiteKnight2 = new Piece(2, 1, "resources/white/whiteKnight.png", ren, 600, 700);
	Piece *whiteRook2 = new Piece(1, 1, "resources/white/whiteRook.png",     ren, 700, 700);

	pieces.push_back(whiteRook1);
	pieces.push_back(whiteKnight1);	
	pieces.push_back(whiteBishop1);
	pieces.push_back(whiteQueen);
	pieces.push_back(whiteKing);
	pieces.push_back(whiteRook2);	
	pieces.push_back(whiteBishop2);
	pieces.push_back(whiteKnight2);

	Piece *whitePawn1 = new Piece(0, 1, "resources/white/whitePawn.png", ren,   0, 600);
	Piece *whitePawn2 = new Piece(0, 1, "resources/white/whitePawn.png", ren, 100, 600);
	Piece *whitePawn3 = new Piece(0, 1, "resources/white/whitePawn.png", ren, 200, 600);
	Piece *whitePawn4 = new Piece(0, 1, "resources/white/whitePawn.png", ren, 300, 600);
	Piece *whitePawn5 = new Piece(0, 1, "resources/white/whitePawn.png", ren, 400, 600);
	Piece *whitePawn6 = new Piece(0, 1, "resources/white/whitePawn.png", ren, 500, 600);
	Piece *whitePawn7 = new Piece(0, 1, "resources/white/whitePawn.png", ren, 600, 600);
	Piece *whitePawn8 = new Piece(0, 1, "resources/white/whitePawn.png", ren, 700, 600);
	
	pieces.push_back(whitePawn1);
	pieces.push_back(whitePawn2);
	pieces.push_back(whitePawn3);
	pieces.push_back(whitePawn4);
	pieces.push_back(whitePawn5);
	pieces.push_back(whitePawn6);
	pieces.push_back(whitePawn7);
	pieces.push_back(whitePawn8);



								// type, team, file, renderer, location
	// tileArray[0][1]->setPiece(1, 1, "resources/black/blackRook.png", ren, 0, 0); //1 
	// tileArray[0][2]->setPiece(2, 1, "resources/black/blackKnight.png", ren, 0, 100); //2
	// tileArray[0][3]->setPiece(3, 1, "resources/black/blackBishop.png", ren, 0, 200);
	// tileArray[0][4]->setPiece(4, 1, "resources/black/blackQueen.png", ren, 0, 300);
	// tileArray[0][5]->setPiece(5, 1, "resources/black/blackKing.png", ren, 0, 400);
	// tileArray[0][6]->setPiece(3, 1, "resources/black/blackBishop.png", ren, 0, 500);
	// tileArray[0][0]->setPiece(2, 1, "resources/black/blackKnight.png", ren, 0, 600);
	// tileArray[0][0]->setPiece(1, 1, "resources/black/blackRook.png", ren, 0, 700);
}

// void Tile::setPiece(int a, bool b, const char* src, SDL_Renderer* ren, int x, int y) {
// 	piece = new Piece(a, b, src, ren, x, y);

// 	return;
// }


std::vector<Piece*> Board::getPiecesVector() {
	return pieces;
}