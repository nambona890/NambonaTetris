#include <Piece.h>
#include <Main.h>

static float fallTimer = 0;
static float fallWait = 0.5;

int PieceInit()
{
	time_t t;
	srand((unsigned)t);
	nextPiece = rand() % 7;
}

int DropPiece()
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

			if (blockGrid[curY+1][curX]!=PIECE_NONE||curY==19)
			{
				goto PieceWait_For_Break;
			}
		}
		pieceY++;
		goto PieceWait_If_Break;
		PieceWait_For_Break:
		for (int i = 0; i < 4; i++)
		{
			char curX = *currentPiecePtr[pieceRotation][i][0] + pieceX;
			char curY = *currentPiecePtr[pieceRotation][i][1] + pieceY;

			blockGrid[curY][curX] = currentPiece;
		}
	}
	PieceWait_If_Break:
}