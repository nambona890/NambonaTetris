#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <stdbool.h>
#include <math.h>

#pragma once
#define TAU (M_PI * 2)

static const short width = 1024;
static const short height = 768;

static const char mapWidth = 10;
static const char mapHeight = 20;

static const char tileSize = 32;

static float deltaTime = 0.03;

static char nextPiece;
static char currentPiece;
static char (*currentPiecePtr)[4][4][2];

static char pieceRotation;
static char pieceX;
static char pieceY;

static char blockGrid[20][10] = {
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


static const char iPiece[4][4][2] =
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

static const int sPiece[4][4][2] =
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

static const int jPiece[4][4][2] =
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

static const int zPiece[4][4][2] =
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

static const int tPiece[4][4][2] =
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

static const int oPiece[4][4][2] =
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

static const int lPiece[4][4][2] =
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



int ScreenDraw(SDL_Renderer* renderer, SDL_Texture* canvas);

int ScreenRender(SDL_Renderer* renderer, SDL_Texture* canvas);

int mod(int a, int b);