#include <Screen.h>

int LoadImages(SDL_Renderer* renderer)
{
	pieceTile = IMG_LoadTexture(renderer,"Images/Piece.png");
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