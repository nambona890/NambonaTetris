#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <math.h>

#ifndef GLOBALSHIT
#define GLOBALSHIT

#define TAU (M_PI * 2)

extern const short width = 1024;
extern const short height = 768;

extern const char mapWidth = 10;
extern const char mapHeight = 20;

extern const char tileSize = 32;

extern const short screenOffsetX = 352;
extern const short screenOffsetY = 40;

extern float deltaTime = 0.03;

extern SDL_Event event;

extern char nextPiece;
extern char currentPiece;
extern char(*currentPiecePtr)[4][4][2];

extern char pieceRotation;
extern char pieceX;
extern char pieceY;

extern bool keyPress[6] = { 0,0,0,0,0,0 };
extern bool keyHeld[6] = { 0,0,0,0,0,0 };

extern char blockGrid[21][10] = {
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


extern const char iPiece[4][4][2] =
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

extern const char sPiece[4][4][2] =
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

extern const char jPiece[4][4][2] =
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

extern const char zPiece[4][4][2] =
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

extern const char oPiece[4][4][2] =
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

extern const char lPiece[4][4][2] =
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
#endif