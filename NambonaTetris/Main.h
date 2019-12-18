#pragma once
#define TAU (M_PI * 2)
#define PIECE_I 0
#define PIECE_S 1
#define PIECE_J 2
#define PIECE_Z 3
#define PIECE_T 4
#define PIECE_O 5

static const int width = 1024;
static const int height = 768;

static const int mapWidth = 10;
static const int mapHeight = 20;

static const int tileSize = 32;

static float deltaTime = 10;

int ScreenDraw(SDL_Renderer* renderer, SDL_Texture* canvas);

int ScreenRender(SDL_Renderer* renderer, SDL_Texture* canvas);

int mod(int a, int b);

struct piece
{
	int type;
	int x;
	int y;
};

static const int iPiece[4][4][2] =
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