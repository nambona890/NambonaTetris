#include <Global.h>
#pragma once


SDL_Texture* pieceTile = NULL;
SDL_Rect pieceTileSrc;

extern int LoadImages(SDL_Renderer* renderer);

extern int ScreenDraw(SDL_Renderer* renderer, SDL_Texture* canvas);

extern int ScreenRender(SDL_Renderer* renderer, SDL_Texture* canvas);