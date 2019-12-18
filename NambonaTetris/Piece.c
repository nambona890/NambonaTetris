#include <Piece.h>

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
			char curX = *currentPiecePtr[pieceRotation][i][0]+pieceX;
			char curY = *currentPiecePtr[pieceRotation][i][1]+pieceY;

			if (blockGrid[curY+1][curX]!=PIECE_NONE||curY>18)
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
			if (blockGrid[curY][curX] != PIECE_NONE || pieceX<0)
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
			if (blockGrid[curY][curX] != PIECE_NONE || pieceX>9)
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