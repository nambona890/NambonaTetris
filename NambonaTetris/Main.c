#include <Main.h>

SDL_Event event;
char nextPiece;
char currentPiece;
char(*currentPiecePtr)[4][4][2];
char pieceRotation;
char pieceX;
char pieceY;

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