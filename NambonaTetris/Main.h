#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <math.h>

#pragma once

#define TAU (M_PI * 2)

const int width = 1024;
const int height = 768;

const int mapWidth = 10;
const int mapHeight = 20;

const int tileSize = 32;

const int screenOffsetX = 352;
const int screenOffsetY = 40;

float deltaTime = 0.03;

SDL_Event event;

int nextPiece;
int currentPiece;
int(*currentPiecePtr)[4][4][2];

int pieceRotation;
int pieceX;
int pieceY;

bool keyPress[6] = { 0,0,0,0,0,0 };
bool keyHeld[6] = { 0,0,0,0,0,0 };

int blockGrid[21][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

#define PIECE_NONE 0
#define PIECE_I 1
#define PIECE_S 2
#define PIECE_J 3
#define PIECE_Z 4
#define PIECE_T 5
#define PIECE_O 6
#define PIECE_L 7


const int iPiece[4][4][2] =
{
	{
		{-2,0},
		{-1,0},
		{0,0},
		{1,0}
	},
	{
		{0,-2},
		{0,-1},
		{0,0},
		{0,1}
	},
	{
		{-2,0},
		{-1,0},
		{0,0},
		{1,0}
	},
	{
		{0,-2},
		{0,-1},
		{0,0},
		{0,1}
	}
};

const int sPiece[4][4][2] =
{
	{
		{-1,1},
		{0,1},
		{0,0},
		{1,0}
	},
	{
		{0,-1},
		{0,0},
		{1,0},
		{1,1}
	},
	{
		{-1,1},
		{0,1},
		{0,0},
		{1,0}
	},
	{
		{0,-1},
		{0,0},
		{1,0},
		{1,1}
	}
};

const int jPiece[4][4][2] =
{
	{
		{-1,0},
		{0,0},
		{1,0},
		{1,1}
	},
	{
		{-1,1},
		{0,1},
		{0,0},
		{0,-1}
	},
	{
		{-1,-1},
		{-1,0},
		{0,0},
		{1,0}
	},
	{
		{1,-1},
		{0,-1},
		{0,0},
		{0,1}
	}
};

const int zPiece[4][4][2] =
{
	{
		{-1,0},
		{0,0},
		{0,1},
		{1,1}
	},
	{
		{0,1},
		{0,0},
		{1,0},
		{1,-1}
	},
	{
		{-1,0},
		{0,0},
		{0,1},
		{1,1}
	},
	{
		{0,1},
		{0,0},
		{1,0},
		{1,-1}
	}
};

extern const int tPiece[4][4][2] =
{
	{
		{-1,0},
		{0,0},
		{1,0},
		{0,1}
	},
	{
		{0,-1},
		{0,0},
		{0,1},
		{-1,0}
	},
	{
		{-1,0},
		{0,0},
		{1,0},
		{0,-1}
	},
	{
		{0,-1},
		{0,0},
		{0,1},
		{1,0}
	}
};

const int oPiece[4][4][2] =
{
	{
		{-1,0},
		{0,0},
		{-1,1},
		{0,1}
	},
	{
		{-1,0},
		{0,0},
		{-1,1},
		{0,1}
	},
	{
		{-1,0},
		{0,0},
		{-1,1},
		{0,1}
	},
	{
		{-1,0},
		{0,0},
		{-1,1},
		{0,1}
	}
};

const int lPiece[4][4][2] =
{
	{
		{-1,1},
		{-1,0},
		{0,0},
		{1,0}
	},
	{
		{-1,-1},
		{0,-1},
		{0,0},
		{0,1}
	},
	{
		{-1,0},
		{0,0},
		{1,0},
		{1,-1}
	},
	{
		{0,-1},
		{0,0},
		{0,1},
		{1,1}
	}
};

SDL_Texture* pieceTile = NULL;
SDL_Rect pieceTileSrc;

float fallTimer = 0;
float fallWait = 0.5;

int PieceInit();

int PieceDrop();

int PieceWait();

int PieceRotate(bool cw);

int PieceMove(bool dir);

int LoadImages(SDL_Renderer* renderer);

int ScreenDraw(SDL_Renderer* renderer, SDL_Texture* canvas);

int ScreenRender(SDL_Renderer* renderer, SDL_Texture* canvas);

int mod(int a, int b);

int GameLogic();

int GetInput();




int LoadImages(SDL_Renderer* renderer);

int ScreenDraw(SDL_Renderer* renderer, SDL_Texture* canvas);

int ScreenRender(SDL_Renderer* renderer, SDL_Texture* canvas);


int PieceInit();

int PieceWait();

int PieceRotate(bool cw);

int PieceMove(bool dir);