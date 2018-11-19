#pragma once
#include "../include/game.h"
#include "../include/TextureManager.h"
#include <stdlib.h>
#include "../include/piece.h"
#include <vector>

SDL_Texture *boardTex;
std::vector<Piece*> pieces;
Piece *pawn1, *rook1;


Game::Game() {
	whiteTurn = true;
	blackTurn = false;

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
					isBegan = true;
					break;
			}
		case SDL_MOUSEBUTTONDOWN:
			if ( event.button.button == SDL_BUTTON_LEFT ) {
				for (int i = 0; i < piecesVector.size(); i++) {
					// std::cout << "click" << std::endl;
					position mousePos;
					mousePos.x = event.button.x;
					mousePos.y = event.button.y;
					pieceClickCheck(mousePos, piecesVector.at(i));
				}
			}
		default:
			break;
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
	left = pieceR->x;
	right = pieceR->x + pieceR->w;
	top = pieceR->y;
	bottom = pieceR->y + pieceR->h;


	if (mousePos.x < top) piece->setClicked(false);
	else if (mousePos.x > bottom) piece->setClicked(false);
	else if (mousePos.y > right) piece->setClicked(false);
	else if (mousePos.y < left) piece->setClicked(false);
	else {
		piece->setClicked(true);
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
				std::cout << "king clicked!" << std::endl;
				break;
		} 
	}

	return;
}