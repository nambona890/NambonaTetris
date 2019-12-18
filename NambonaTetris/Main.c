#include <Main.h>

SDL_Event event;
char nextPiece;
char currentPiece;
char(*currentPiecePtr)[4][4][2];
char pieceRotation;
char pieceX;
char pieceY;
const short width;
const short height;
const char mapWidth;
const char mapHeight;
const char tileSize;
const short screenOffsetX;
const short screenOffsetY;
float deltaTime;
bool keyPress[6];
bool keyHeld[6];
char blockGrid[21][10];
const char iPiece[4][4][2];
const char sPiece[4][4][2];
const char jPiece[4][4][2];
const char zPiece[4][4][2];
const char tPiece[4][4][2];
const char oPiece[4][4][2];
const char lPiece[4][4][2];

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Nambona's Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOWEVENT);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	bool running = true;
	float oldTime = 0, newTime = 0;
	SDL_Texture* canvas = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	PieceInit();
	LoadImages(renderer);
	while (running)
	{
		oldTime = newTime;
		newTime = SDL_GetTicks();
		deltaTime = (newTime - oldTime)/1000;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		GameLogic();
		ScreenDraw(renderer, canvas);
		ScreenRender(renderer, canvas);
		SDL_Delay(1);
	}
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

int mod(int a, int b)
{
	int r = a % b;
	return r < 0 ? r + b : r;
}

int GameLogic()
{
	PieceWait();
	GetInput();
}

int GetInput()
{
	while (SDL_PollEvent(&event))
	{
		for (int i = 0; i < 6; i++)
		{
			keyPress[i] = 0;
		}
		switch (event.type)
		{
			case SDL_KEYDOWN:

				switch (event.key.keysym.sym)
				{
					case SDLK_LEFT:
						SetPress(0);
						break;
					case SDLK_RIGHT:
						SetPress(1);
						break;
					case SDLK_UP:
						SetPress(2);
						break;
					case SDLK_DOWN:
						SetPress(3);
						break;
					case SDLK_z:
						SetPress(4);
						break;
					case SDLK_x:
						SetPress(5);
						break;
					default:
						break;
				}

				break;
			default:
				break;
		}
	}

	if (keyPress[0])
	{
		PieceMove(0);
	}
	if (keyPress[1])
	{
		PieceMove(1);
	}
	if (keyPress[4])
	{
		PieceRotate(0);
	}
	if (keyPress[5])
	{
		PieceRotate(1);
	}

}

int SetPress(char key)
{
	if (!keyHeld[key])
	{
		keyPress[key] == 1;
	}
	else
	{
		keyPress[key] == 0;
	}
	keyHeld[key] == 1;
}






int LoadImages(SDL_Renderer* renderer)
{
	pieceTile = IMG_LoadTexture(renderer, "Images/Piece.png");
	pieceTileSrc.x = 0;
	pieceTileSrc.y = 0;
	pieceTileSrc.w = tileSize;
	pieceTileSrc.h = tileSize;
}

int ScreenDraw(SDL_Renderer* renderer, SDL_Texture* canvas)
{
	SDL_SetRenderTarget(renderer, canvas);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 192, 192, 192);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (blockGrid[i][j] != PIECE_NONE)
			{
				SDL_Rect pieceDest;
				pieceDest.w = tileSize;
				pieceDest.h = tileSize;

				pieceDest.x = (j * tileSize) + screenOffsetX;
				pieceDest.y = (j * tileSize) + screenOffsetY;

				SDL_RenderCopy(renderer, pieceTile, &pieceTileSrc, &pieceDest);
			}
		}
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	for (int i = 0; i < 4; i++)
	{
		SDL_Rect pieceDest;
		pieceDest.w = tileSize;
		pieceDest.h = tileSize;

		pieceDest.x = (((char)&currentPiecePtr[pieceRotation][i][0] + pieceX) * tileSize) + screenOffsetX;
		pieceDest.y = (((char)&currentPiecePtr[pieceRotation][i][1] + pieceY) * tileSize) + screenOffsetY;
	}

	return 0;
}

int ScreenRender(SDL_Renderer* renderer, SDL_Texture* canvas)
{
	SDL_SetRenderTarget(renderer, NULL);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, canvas, NULL, NULL);
	SDL_RenderPresent(renderer);
	return 0;
}







int PieceInit()
{
	time_t t;
	srand((unsigned)time(&t));
	nextPiece = rand() % 7;
	PieceDrop();
}

int PieceDrop()
{
	currentPiece = nextPiece;
	nextPiece = rand() % 7;
	pieceRotation = 0;
	pieceX = 5;
	pieceY = 0;
	switch (currentPiece)
	{
	case PIECE_I:
		currentPiecePtr = &iPiece;
		break;
	case PIECE_S:
		currentPiecePtr = &sPiece;
		break;
	case PIECE_J:
		currentPiecePtr = &jPiece;
		break;
	case PIECE_Z:
		currentPiecePtr = &zPiece;
		break;
	case PIECE_T:
		currentPiecePtr = &tPiece;
		break;
	case PIECE_O:
		currentPiecePtr = &oPiece;
		break;
	case PIECE_L:
		currentPiecePtr = &lPiece;
		break;
	default:
		currentPiecePtr = NULL;
		break;
	}
}

int PieceWait()
{
	fallTimer += deltaTime;
	if (fallTimer > fallWait)
	{
		fallTimer = 0;
		for (int i = 0; i < 4; i++)
		{
			char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;

			if (blockGrid[curY + 1][curX] != PIECE_NONE || curY > 18)
			{
				goto PieceWait_For_Break1;
			}
		}
		pieceY++;
		goto PieceWait_If_Break;
	PieceWait_For_Break1:
		for (int i = 0; i < 4; i++)
		{
			char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;

			blockGrid[curY][curX] = currentPiece;
		}
		for (int i = 0; i < 20; i++)
		{
			bool clear = true;
			for (int j = 0; j < 10; j++)
			{
				if (blockGrid[i][j] == PIECE_NONE)
				{
					clear = false;
				}
			}
			if (clear)
			{
				for (int j = 0; j < 10; j++)
				{
					blockGrid[0][j] = PIECE_NONE;
				}
				if (i > 0)
				{
					for (int j = i; j >= 0; j++)
					{
						for (int k = 0; k < 10; k++)
						{
							blockGrid[j][k] = blockGrid[j - 1][k];
						}
					}
				}
			}
			PieceDrop();
		}
	}
PieceWait_If_Break:
	return;
}

int PieceRotate(bool cw)
{
	bool fail = false;
	char pieceRotationTemp = pieceRotation;
	char pieceXTemp = pieceX;
	char pieceYTemp = pieceY;
	if (cw)
	{
		if (pieceRotation < 3)
		{
			pieceRotation++;
		}
		else
		{
			pieceRotation = 0;
		}
	}
	else
	{
		if (pieceRotation > 0)
		{
			pieceRotation--;
		}
		else
		{
			pieceRotation = 3;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char curX = *currentPiecePtr[pieceRotation][j][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][j][1] + pieceY;
			if (blockGrid[curY][curX] != PIECE_NONE || pieceX < 0)
			{
				pieceX++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
		char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;
		if (blockGrid[curY][curX] != PIECE_NONE || pieceX < 0)
		{
			fail = true;
		}
	}
	if (!fail)
	{
		return;
	}
	fail = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char curX = *currentPiecePtr[pieceRotation][j][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][j][1] + pieceY;
			if (blockGrid[curY][curX] != PIECE_NONE || pieceX > 9)
			{
				pieceX--;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
		char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;
		if (blockGrid[curY][curX] != PIECE_NONE || pieceX > 9)
		{
			fail = true;
		}
	}
	if (!fail)
	{
		return;
	}
	fail = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char curX = *currentPiecePtr[pieceRotation][j][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][j][1] + pieceY;
			if (blockGrid[curY][curX] != PIECE_NONE)
			{
				pieceY++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
		char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;
		if (blockGrid[curY][curX] != PIECE_NONE)
		{
			fail = true;
		}
	}
	if (!fail)
	{
		return;
	}
	fail = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char curX = *currentPiecePtr[pieceRotation][j][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][j][1] + pieceY;
			if (blockGrid[curY][curX] != PIECE_NONE || curY > 19)
			{
				pieceY--;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
		char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;
		if (blockGrid[curY][curX] != PIECE_NONE || curY > 19)
		{
			fail = true;
		}
	}
	if (!fail)
	{
		return;
	}

	pieceRotation = pieceRotationTemp;
	pieceX = pieceXTemp;
	pieceY = pieceYTemp;
}

int PieceMove(bool dir)
{
	bool fail = false;
	char pieceXTemp = pieceX;
	char pieceYTemp = pieceY;

	if (dir)
	{
		pieceX++;
	}
	else
	{
		pieceX--;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char curX = *currentPiecePtr[pieceRotation][j][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][j][1] + pieceY;
			if (blockGrid[curY][curX] != PIECE_NONE || pieceX < 0)
			{
				pieceX++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
		char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;
		if (blockGrid[curY][curX] != PIECE_NONE || pieceX < 0)
		{
			fail = true;
		}
	}
	if (!fail)
	{
		return;
	}
	fail = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char curX = *currentPiecePtr[pieceRotation][j][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][j][1] + pieceY;
			if (blockGrid[curY][curX] != PIECE_NONE || pieceX > 9)
			{
				pieceX--;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
		char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;
		if (blockGrid[curY][curX] != PIECE_NONE || pieceX > 9)
		{
			fail = true;
		}
	}
	if (!fail)
	{
		return;
	}
	fail = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char curX = *currentPiecePtr[pieceRotation][j][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][j][1] + pieceY;
			if (blockGrid[curY][curX] != PIECE_NONE)
			{
				pieceY++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
		char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;
		if (blockGrid[curY][curX] != PIECE_NONE)
		{
			fail = true;
		}
	}
	if (!fail)
	{
		return;
	}

	pieceX = pieceXTemp;
	pieceY = pieceYTemp;
}