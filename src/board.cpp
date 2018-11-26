#include "../include/board.h"

Tile::Tile(int x, int y, int a, int b) {
	tileRect.x = x * 100;  // may need fixing
	tileRect.y = y * 100;   // maky need fixing, reverse x and y
	tileRect.w = 100;
	tileRect.h = 100;
	open = true;
	x_coord = b;
	y_coord = a;
	pos = new position;
	pos->x = y;
	pos->y = x;
	piece = NULL;
}

SDL_Rect* Tile::getRect() {
	return &tileRect;
}

Piece* Tile::getPiece() {
	return piece;
}

void Tile::setPiece(Piece* x) {
	piece = x;
}

void Tile::setClicked(bool c) {
	if (c) clicked = true;
	else clicked = false;
	return;
}

bool Tile::getClicked() {
	return clicked;
}

void Tile::setOpen(bool o) {
	if (o) open = true;
	else open = false;
}

bool Tile::getOpen() {
	return open;
}

char Tile::getTileX() {
	return x_coord;
}

char Tile::getTileY() {
	return y_coord;
}

int Tile::getX() {
	return tileRect.x;
}

int Tile::getY() {
	return tileRect.y;
}

position* Tile::getPos() {
	return pos;
}



//////////////////////////////////////////// BOARD 


Board::Board(SDL_Renderer *ren) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tileArray[i][j] = new Tile(i, j, 65 + i, 65 + j); // beware orientation of I and J
			std::cout << "Assigning tile: " << i << " " << j << std::endl;
		}
	}


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << tileArray[i][j]->getTileX() << tileArray[i][j]->getTileY() << " ";
		}
		std::cout << std::endl;
	}

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

	Piece *whiteRook1 = new Piece(1, 0, "resources/white/whiteRook.png",     ren,   0, 700);	
	Piece *whiteKnight1 = new Piece(2, 0, "resources/white/whiteKnight.png", ren, 100, 700); //2
	Piece *whiteBishop1 = new Piece(3, 0, "resources/white/whiteBishop.png", ren, 200, 700);
	Piece *whiteQueen = new Piece(4, 0, "resources/white/whiteQueen.png",    ren, 300, 700);
	Piece *whiteKing = new Piece(5, 0, "resources/white/whiteKing.png",      ren, 400, 700);
	Piece *whiteBishop2 = new Piece(3, 0, "resources/white/whiteBishop.png", ren, 500, 700);
	Piece *whiteKnight2 = new Piece(2, 0, "resources/white/whiteKnight.png", ren, 600, 700);
	Piece *whiteRook2 = new Piece(1, 0, "resources/white/whiteRook.png",     ren, 700, 700);

	pieces.push_back(whiteRook1);
	pieces.push_back(whiteKnight1);	
	pieces.push_back(whiteBishop1);
	pieces.push_back(whiteQueen);
	pieces.push_back(whiteKing);
	pieces.push_back(whiteRook2);	
	pieces.push_back(whiteBishop2);
	pieces.push_back(whiteKnight2);

	Piece *whitePawn1 = new Piece(0, 0, "resources/white/whitePawn.png", ren,   0, 600);
	Piece *whitePawn2 = new Piece(0, 0, "resources/white/whitePawn.png", ren, 100, 600);
	Piece *whitePawn3 = new Piece(0, 0, "resources/white/whitePawn.png", ren, 200, 600);
	Piece *whitePawn4 = new Piece(0, 0, "resources/white/whitePawn.png", ren, 300, 600);
	Piece *whitePawn5 = new Piece(0, 0, "resources/white/whitePawn.png", ren, 400, 600);
	Piece *whitePawn6 = new Piece(0, 0, "resources/white/whitePawn.png", ren, 500, 600);
	Piece *whitePawn7 = new Piece(0, 0, "resources/white/whitePawn.png", ren, 600, 600);
	Piece *whitePawn8 = new Piece(0, 0, "resources/white/whitePawn.png", ren, 700, 600);
	
	pieces.push_back(whitePawn1);
	pieces.push_back(whitePawn2);
	pieces.push_back(whitePawn3);
	pieces.push_back(whitePawn4);
	pieces.push_back(whitePawn5);
	pieces.push_back(whitePawn6);
	pieces.push_back(whitePawn7);
	pieces.push_back(whitePawn8);

	tileArray[0][0]->setPiece(blackRook1);
	tileArray[0][1]->setPiece(blackKnight1);
	tileArray[0][2]->setPiece(blackBishop1);
	tileArray[0][3]->setPiece(blackQueen);
	tileArray[0][4]->setPiece(blackKing);
	tileArray[0][5]->setPiece(blackBishop2);
	tileArray[0][6]->setPiece(blackKnight2);
	tileArray[0][7]->setPiece(blackRook2);

	tileArray[1][0]->setPiece(blackPawn1);
	tileArray[1][1]->setPiece(blackPawn2);
	tileArray[1][2]->setPiece(blackPawn3);
	tileArray[1][3]->setPiece(blackPawn4);
	tileArray[1][4]->setPiece(blackPawn5);
	tileArray[1][5]->setPiece(blackPawn6);
	tileArray[1][6]->setPiece(blackPawn7);
	tileArray[1][7]->setPiece(blackPawn8);

	tileArray[6][0]->setPiece(whitePawn1);
	tileArray[6][1]->setPiece(whitePawn2);
	tileArray[6][2]->setPiece(whitePawn3);
	tileArray[6][3]->setPiece(whitePawn4);
	tileArray[6][4]->setPiece(whitePawn5);
	tileArray[6][5]->setPiece(whitePawn6);
	tileArray[6][6]->setPiece(whitePawn7);
	tileArray[6][7]->setPiece(whitePawn8);

	tileArray[7][0]->setPiece(whiteRook1);
	tileArray[7][1]->setPiece(whiteKnight1);
	tileArray[7][2]->setPiece(whiteBishop1);
	tileArray[7][3]->setPiece(whiteQueen);
	tileArray[7][4]->setPiece(whiteKing);
	tileArray[7][5]->setPiece(whiteBishop2);
	tileArray[7][6]->setPiece(whiteKnight2);
	tileArray[7][7]->setPiece(whiteRook2);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tileArray[i][j]->getPiece() ==  NULL) tileArray[i][j]->setOpen(true);
			else tileArray[i][j]->setOpen(false);
		}
	}

	printBoardOpenDiagram();

	// for (int i = 0; i < 8; i++) {
	// 	for (int j = 0; j < 8; j++) {
	// 		if (tileArray[i][j]->getOpen() == false) std::cout << "X ";
	// 		else std::cout << "O ";
 // 		}
	// 	std::cout << std::endl;
	// }


}


std::vector<Piece*> Board::getPiecesVector() {
	return pieces;
}


Tile* Board::getTile(int x, int y) {
	// std::cout << tileArray[x][y]->getTileX() << tileArray[x][y]->getTileY()<< std::endl;
	return tileArray[x][y];
}

void Board::printBoardOpenDiagram() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tileArray[i][j]->getOpen() == false) std::cout << "X ";
			else std::cout << "O ";
 		}
		std::cout << std::endl;
	}
}