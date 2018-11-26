#pragma once
#include "../include/game.h"
#include "../include/TextureManager.h"
#include <stdlib.h>
#include "../include/piece.h"
#include <vector>
#include <cmath>

SDL_Texture *boardTex;
std::vector<Piece*> pieces;
Piece *pawn1, *rook1;


Game::Game() {
	whiteTurn = true;
	blackTurn = false;
	pieceSelected = false;

}

Game::~Game() {
	// board = new Board(renderer);
}

void Game::Reset() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {

	int flags = 0;
	if (fullScreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) { // confirm window was created
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) { // confirm renderer was created
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	} else {
		isRunning = false;
	}

	boardTex = TextureManager::LoadTexture("resources/board/board.png", renderer);
	board = new Board(renderer);

}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	std::vector<Piece*> piecesVector = board->getPiecesVector();

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_RETURN:
					board->printBoardOpenDiagram();
					break;
			}
		case SDL_MOUSEBUTTONDOWN: 
			position mousePos;
			if ( event.button.button == SDL_BUTTON_LEFT ) {				
				if (pieceSelected == false) {
					std::cout << "piece is NOT selected" << std::endl;
					mousePos.y = (event.button.x / 100);
					mousePos.x = (event.button.y / 100);
					// std::cout << mousePos.x << " " << mousePos.y << std::endl;
					selectedTile = board->getTile(mousePos.x, mousePos.y);
					if (selectedTile->getPiece() != NULL) {
						pieceSelected = true;
						selectedPiece = selectedTile->getPiece();
						selectedPiece->setClicked(true);
						std::cout << selectedTile->getTileX() << selectedTile->getTileY() << std::endl;						
					}
				} else {
					mousePos.y = (event.button.x / 100);
					mousePos.x = (event.button.y / 100);
					Tile *target;
					target = board->getTile(mousePos.x, mousePos.y);
					if (target->getOpen() == false) {
						if (target->getPiece()->getClicked() == true) {
							std::cout << "clicked selected piece again!" << std::endl;
							pieceSelected = false;
							selectedPiece->setClicked(false);
							selectedTile = NULL;
							selectedPiece = NULL;
							break;
						} else {
							std::cout << "Invalid move!" << std::endl;
							break;
						}		
					}

					if (checkValidMove(selectedPiece, target)) {
						// std::cout << target->getTileX() << target->getTileY() << std::endl;
						target->setOpen(false);
						target->setPiece(selectedPiece);
						selectedPiece->setClicked(false);
						selectedTile->setPiece(NULL);
						selectedTile->setOpen(true);
						selectedPiece->setLocation(target->getY(), target->getX());
						pieceSelected = false;					
					} else {
						std::cout << "Invalid move!" << std::endl;
						pieceSelected = false;
						selectedPiece->setClicked(false);
						selectedTile = NULL;
						selectedPiece = NULL;
					}
				}
			render();
			break;
		default:
			break;
		}
	} 
}



void Game::update() {



}

void Game::renderMenu() {
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::render() {
	SDL_RenderClear(renderer);
	// this is where we would add stuff to render
	SDL_RenderCopy(renderer, boardTex, NULL, NULL);
	std::vector<Piece*> piecesVector = board->getPiecesVector();
	for (int i = 0; i < piecesVector.size(); i++ ) {
		SDL_RenderCopy(renderer, piecesVector.at(i)->getTexture(), NULL, piecesVector.at(i)->getRect());
	}
	SDL_RenderPresent(renderer);

}

bool Game::running() {
	return isRunning;
}

bool Game::began() {
	return isBegan;
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}


// finish thisssssss
bool Game::checkCollision(SDL_Rect a, SDL_Rect b) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB) return false;
	else if (topA >= bottomB) return false;
	else if (rightA <= leftB) return false;
	else if (leftA >= rightB) return false;
	else return true;
}


void Game::pieceClickCheck(position mousePos, Piece *piece) {
	SDL_Rect *pieceR = piece->getRect();
	int left, right, top, bottom;
	left = pieceR->y;
	right = pieceR->y + pieceR->w;
	top = pieceR->x;
	bottom = pieceR->x + pieceR->h;

	// std::cout << "Piece x coord = " << pieceR->x << std::endl;
	// std::cout << "Piece y coord = " << pieceR->y << std::endl;

	if (mousePos.x < top) piece->setClicked(false);
	else if (mousePos.x > bottom) piece->setClicked(false);
	else if (mousePos.y > right) piece->setClicked(false);
	else if (mousePos.y < left) piece->setClicked(false);
	else {
		pieceSelected = true;
		piece->setClicked(true);
		selectedPiece = piece;
		switch (piece->getType()) {
			case 0:
				std::cout << "Pawn clicked!" << std::endl;
				break;
			case 1:
				std::cout << "Rook clicked!" << std::endl;
				break;		
			case 2:
				std::cout << "Knight clicked!" << std::endl;
				break;
			case 3:
				std::cout << "Bishop clicked!" << std::endl;
				break;
			case 4:
				std::cout << "Queen clicked!" << std::endl;
				break;
			case 5:
				std::cout << "King clicked!" << std::endl;
				break;
		} 
	}

	return;
}

bool Game::checkValidMove(Piece* piece, Tile* tile) {

	int x = 1;
	if (piece->getTeam() == false) x = -1;
	int startingPos = 1;
	if (piece->getTeam() == false) startingPos = 6;


	int tileX = tile->getPos()->x;
	int tileY = tile->getPos()->y;
	int pieceX = piece->getPos()->x;
	int pieceY = piece->getPos()->y;

	std::cout << "Tile: " << tileX << "," << tileY << std::endl;
	std::cout << "Piece: " << pieceX << "," << pieceY << std::endl;
	std::cout << "Tile Alpha: " << tile->getTileX() << "," << tile->getTileY() << std::endl;

	int direction = 0;

 	switch(piece->getType()) {

		case 0: // pawn
			if (tileY - pieceY == x) {
				piece->setPos(pieceX, pieceY + (1*x));
				return true;
			} else if ((pieceY == startingPos) && (tileY - pieceY == (2 * x))) {
				piece->setPos(pieceX, pieceY + (2 * x));
				return true;
			} else return false;
			break;

		case 1: // rook

			if (tileX - pieceX == 0 || tileY - pieceY == 0) {
				if (tileX - pieceX == 0) {
					int dist = tileY - pieceY;
					if (pieceY - tileY > 0) direction = -1;
					else if (pieceY - tileY < 0) direction = 1;
					// std::cout << "Beginning to check path..." << std::endl;
					for (int i = 0; i < abs(dist); i++) {
						Tile *temp = board->getTile(pieceY + (i * direction), pieceX);
						// std::cout << temp->getTileX() << temp->getTileY();
						if (temp->getOpen() == false && i != 0) {
							// std::cout << "*";
							// std::cout << std::endl << "...ERROR, PATH IS NOT CLEAR!" << std::endl;
							// std::cout << "Occupied by: " << temp->getPiece()->getTeam() << " " << temp->getPiece()->getType() << std::endl;
							return false;
						}
					}
					piece->setPos(tileX, tileY);
					// std::cout << "...done, path is clear." << std::endl;
					return true;
				} else if (tileY - pieceY == 0) {
					int dist = tileX - pieceX;
					if (pieceX - tileX > 0) direction = -1;
					else if (pieceX - tileX < 0) direction = 1;
					for (int i = 0; i < abs(dist); i++) {
						Tile *temp = board->getTile(pieceY, pieceX + (i * direction));
						if (temp->getOpen() == false && i != 0) {
							return false;
						}
					}
					piece->setPos(tileX, tileY);
					return true;
				}
			}

			return false;
			break;

		case 2: // knight
			return false;
			break;
		case 3: // bishop
			return false;
			break;
		case 4: // queen
			return false;
			break;
		case 5: // king
			return false;
			break;
	}
}


bool Game::tileClickCheck(position mousePos, Tile* selectedTile) {
	SDL_Rect *tileR = selectedTile->getRect();
	int left, right, top, bottom;
	left = tileR->y;
	right = tileR->y + tileR->w;
	top = tileR->x;
	bottom = tileR->x + tileR->h;

	if (mousePos.x < top) {
		return false;
	}
	else if (mousePos.x > bottom) {		
		return false;
	}
	else if (mousePos.y > right) { 
		return false;
	}
	else if (mousePos.y < left) {
		return false;
	}
	else {
		selectedTile->setClicked(true);
		std::cout << "Tile clicked! " << selectedTile->getTileX() << selectedTile->getTileY() << std::endl;
		return true;
	}
}
