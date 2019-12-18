#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <math.h>

#pragma once

#define TAU (M_PI * 2)

const short width = 1024;
const short height = 768;

const char mapWidth = 10;
const char mapHeight = 20;

const char tileSize = 32;

const short screenOffsetX = 352;
const short screenOffsetY = 40;

float deltaTime = 0.03;

SDL_Event event;

char nextPiece;
char currentPiece;
char(*currentPiecePtr)[4][4][2];

char pieceRotation;
char pieceX;
char pieceY;

bool keyPress[6] = { 0,0,0,0,0,0 };
bool keyHeld[6] = { 0,0,0,0,0,0 };

char blockGrid[21][10] = {
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


const char iPiece[4][4][2] =
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

const char sPiece[4][4][2] =
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

const char jPiece[4][4][2] =
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

const char zPiece[4][4][2] =
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

extern const char tPiece[4][4][2] =
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

const char oPiece[4][4][2] =
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

const char lPiece[4][4][2] =
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