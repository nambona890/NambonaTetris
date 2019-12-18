#include <Global.h>
#pragma once


SDL_Texture* pieceTile = NULL;
SDL_Rect pieceTileSrc;

int LoadImages(SDL_Renderer* renderer);

int ScreenDraw(SDL_Renderer* renderer, SDL_Texture* canvas);

int ScreenRender(SDL_Renderer* renderer, SDL_Texture* canvas);