#include <Global.h>
#pragma once

float fallTimer = 0;
float fallWait = 0.5;

extern int PieceInit();

int PieceDrop();

extern int PieceWait();

extern int PieceRotate(bool cw);

extern int PieceMove(bool dir);