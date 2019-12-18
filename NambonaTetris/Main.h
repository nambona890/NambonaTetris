#include <Global.h>

#pragma once


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