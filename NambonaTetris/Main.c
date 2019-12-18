#include <Main.h>


int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Nambona's Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOWEVENT);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	bool running = true;
	SDL_Event event;
	float oldTime = 0, newTime = 0;
	SDL_Texture* canvas = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
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
		ScreenDraw(renderer, canvas);
		ScreenRender(renderer, canvas);
		SDL_Delay(1);
	}
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

int ScreenDraw(SDL_Renderer* renderer, SDL_Texture* canvas)
{
	SDL_SetRenderTarget(renderer, canvas);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
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

int mod(int a, int b)
{
	int r = a % b;
	return r < 0 ? r + b : r;
}