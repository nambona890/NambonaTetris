#include <Global.h>
#pragma once

static float fallTimer = 0;
static float fallWait = 0.5;

int PieceInit();

int PieceDrop();

int PieceWait();

int PieceRotate(bool cw);

int PieceMove(bool dir);