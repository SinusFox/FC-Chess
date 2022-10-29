#include "FC-Chess.h"

FCC::Chess::Chess()
{
    // initialize user interface
    tui.startup();

    //start game
    FCC::Chess::mainMenu();
}

void FCC::Chess::mainMenu()
{
    /* TO DO
    - Add options
    - call FCC::Chess::GameLoop when game begins */
}

void FCC::Chess::gameLoop()
{
    // initialize board
    FCC::Chess::startupGame();

    // main loop
    while(!gameEnded)
    {
        /* To Do: user input */
        tui.mainLoop();
    }
}

void FCC::Chess::startupGame()
{
    // preparing board: colors
    for (int8_t i = 0; i < 8; i++) {
        for (uint8_t j = 0; i < 2; i++) {
            posColor[i][j] = PiecesColors::BLACK;
        }
        for (uint8_t j = 6; i < 8; i++) {
            posColor[i][j] = PiecesColors::WHITE;
        }
        for (uint8_t j = 2; i < 7; i++) {
            posColor[i][j] = PiecesColors::NONE;
        }
    }

    // preparing board: pieces
    for (int8_t i = 0; i < 8; i++) {
        posPieces[1][i] = Pieces::PAWN;
        posPieces[6][i] = Pieces::PAWN;
    }
    for (int8_t i = 0; i < 2; i++) {
        posPieces[i][0] = Pieces::ROOK;
        posPieces[i][7] = Pieces::ROOK;
        posPieces[i][1] = Pieces::KNIGHT;
        posPieces[i][6] = Pieces::KNIGHT;
        posPieces[i][2] = Pieces::BISHOP;
        posPieces[i][5] = Pieces::BISHOP;
        posPieces[i][3] = Pieces::KING;
        posPieces[i][4] = Pieces::QUEEN;
    }
}

bool FCC::Chess::checkIsEnemyOnField(uint8_t x, uint8_t y)
{
    // Check if the color of the selected piece/field is the opposite of the target piece/field => is true then
    if (posColor[x][y] == FCC::PiecesColors::BLACK && posColor[selX][selY] == FCC::PiecesColors::WHITE) return true;
    if (posColor[x][y] == FCC::PiecesColors::WHITE && posColor[selX][selY] == FCC::PiecesColors::BLACK) return true;
    return false;
}

bool FCC::Chess::checkIsPosInBounds(uint8_t x, uint8_t y)
{
    // check if X and Y values are below 8. No negative values have to be checked since the var type is unsigned int
    if (x <= 7 && y <= 7)
    {
        return true;
    }
    return false;
}

void FCC::Chess::checkAllowedMoves()
{
    // reset all allowed positions
    for (uint8_t i = 0; i <= 7; i++)
    {
        for (uint8_t j = 0; j <= 7; j++)
        {
            posPossible[i][j] = false;
        }
    }

    // check piece and then check possible moves accordingly
    switch (FCC::Chess::posPieces[FCC::Chess::selX][FCC::Chess::selY]) {
        case FCC::Pieces::PAWN:
            break;
        case FCC::Pieces::ROOK:
            break;
        default:
            tui.errOutput(&lang.errNoPieceOnPosition);
            break;
    }
}

void FCC::Chess::checkMovesHorizontal()
{
    // checking positions to the right
    for (uint8_t i = selX; i <= 7; i++)
    {
        if (checkIsFriendlyOnField(i, selY)) break;
        posPossible[i][selY] = true;
        if (checkIsEnemyOnField(i, selY)) break;
    }

    // checking positions to the left
    for (uint8_t i = selX; i >= 0; i--)
    {
        if (checkIsFriendlyOnField(i, selY)) break;
        posPossible[i][selY] = true;
        if (checkIsEnemyOnField(i, selY)) break;
    }
}

void FCC::Chess::checkMovesVertical()
{
    // checking positions above
    for (uint8_t i = selY; i <= 7; i++)
    {
        if (checkIsFriendlyOnField(selX, i)) break;
        posPossible[selX][i] = true;
        if (checkIsEnemyOnField(selX, i)) break;
    }

    // checking positions below
    for (uint8_t i = selY; i >= 0; i--)
    {
        if (checkIsFriendlyOnField(selX, i)) break;
        posPossible[selX][i] = true;
        if (checkIsEnemyOnField(selX, i)) break;
    }
}

void FCC::Chess::checkMovesDiagonal()
{
    // checking positions up-right
    for (uint8_t i = 1; checkIsPosInBounds(selX + i, selY + i); i++)
    {
        if (checkIsFriendlyOnField(selX + i, selY + i)) break;
        posPossible[selX + i][selY + i] = true;
        if (checkIsEnemyOnField(selX + i, selY + i)) break;
    }

    // checking positions below-right
    for (uint8_t i = 1; checkIsPosInBounds(selX + i, selY - i); i++)
    {
        if (checkIsFriendlyOnField(selX + i, selY - i)) break;
        posPossible[selX + i][selY - i] = true;
        if (checkIsEnemyOnField(selX + i, selY - i)) break;
    }

    // checking positions up-left
    for (uint8_t i = 1; checkIsPosInBounds(selX - i, selY + i); i++)
    {
        if (checkIsFriendlyOnField(selX - i, selY + i)) break;
        posPossible[selX - i][selY + i] = true;
        if (checkIsEnemyOnField(selX - i, selY + i)) break;
    }

    // checking positions below-left
    for (uint8_t i = 1; checkIsPosInBounds(selX - i, selY - i); i++)
    {
        if (checkIsFriendlyOnField(selX - i, selY - i)) break;
        posPossible[selX - i][selY - i] = true;
        if (checkIsEnemyOnField(selX - i, selY - i)) break;
    }
}

void FCC::Chess::checkMovesKnight()
{
    // checking possible moves
    if (checkIsPosInBounds(selX + 1, selY + 3)) 
    {
        if (!checkIsFriendlyOnField(selX + 1, selY + 3)) posPossible[selX + 1][selY + 3] = true;
    }

    if (checkIsPosInBounds(selX + 1, selY - 3)) 
    {
        if (!checkIsFriendlyOnField(selX + 1, selY - 3)) posPossible[selX + 1][selY - 3] = true;
    }

    if (checkIsPosInBounds(selX - 1, selY + 3)) 
    {
        if (!checkIsFriendlyOnField(selX - 1, selY + 3)) posPossible[selX - 1][selY + 3] = true;
    }
    
    if (checkIsPosInBounds(selX - 1, selY - 3)) 
    {
        if (!checkIsFriendlyOnField(selX - 1, selY - 3)) posPossible[selX - 1][selY - 3] = true;
    }

    if (checkIsPosInBounds(selX + 3, selY + 1)) 
    {
        if (!checkIsFriendlyOnField(selX + 3, selY + 1)) posPossible[selX + 3][selY + 1] = true;
    }

    if (checkIsPosInBounds(selX + 3, selY - 1)) 
    {
        if (!checkIsFriendlyOnField(selX + 3, selY - 1)) posPossible[selX + 3][selY - 1] = true;
    }
    
    if (checkIsPosInBounds(selX - 3, selY + 1)) 
    {
        if (!checkIsFriendlyOnField(selX - 3, selY + 1)) posPossible[selX - 3][selY + 1] = true;
    }
    
    if (checkIsPosInBounds(selX - 3, selY - 1)) 
    {
        if (!checkIsFriendlyOnField(selX - 3, selY - 1)) posPossible[selX - 3][selY - 1] = true;
    }
}

void FCC::Chess::checkMovesKing()
{
    // creating variables for x and y
    uint8_t i, j;

    // checking possible moves
    i = selX - 1, j = selY + 1;
    for (; i <= selX + 1; i++)
    {
        if (checkIsPosInBounds(i, j))
        {
            if (!checkIsFriendlyOnField(i, j)) posPossible[i][j] = true;
        }
    }

    i = selX - 1, j = selY - 1;
    for (; i <= selX + 1; i++)
    {
        if (checkIsPosInBounds(i, j))
        {
            if (!checkIsFriendlyOnField(i, j)) posPossible[i][j] = true;
        }
    }

    i = selX - 1, j = selY;
    if (checkIsPosInBounds(i, j))
    {
        if (!checkIsFriendlyOnField(i, j)) posPossible[i][j] = true;
    }

    i = selX + 1, j = selY;
    if (checkIsPosInBounds(i, j))
    {
        if (!checkIsFriendlyOnField(i, j)) posPossible[i][j] = true;
    }
}

void FCC::Chess::checkMovesPawn()
{
    // black pieces
    if (posColor[selX][selY] == FCC::PiecesColors::BLACK)
    {
        // creating variables for x and y
        uint8_t i, j;

        // checking possible moves
        i = selX - 1, j = selY - 1;
        for (; i <= selX + 1;)
        {
            if (checkIsPosInBounds(i, j))
            {
                if (checkIsEnemyOnField(i, j)) posPossible[i][j] = true;
            }
            i += 2;
        }

        i = selX, j = selY - 1;
        if (checkIsPosInBounds(i, j))
        {
            if (checkIsPositionClear(i, j)) posPossible[i][j] = true;
        }
    }

    // white pieces
    if (posColor[selX][selY] == FCC::PiecesColors::WHITE)
    {
        // creating variables for x and y
        uint8_t i, j;

        // checking possible moves
        i = selX - 1, j = selY + 1;
        for (; i <= selX + 1;)
        {
            if (checkIsPosInBounds(i, j))
            {
                if (checkIsEnemyOnField(i, j)) posPossible[i][j] = true;
            }
            i += 2;
        }

        i = selX, j = selY + 1;
        if (checkIsPosInBounds(i, j))
        {
            if (checkIsPositionClear(i, j)) posPossible[i][j] = true;
        }
    }
}

bool FCC::Chess::checkIsPawnChangingToQueen()
{
    //black pieces
    if (posColor[selX][selY] == FCC::PiecesColors::BLACK)
    {
        if (selY == 0) return true;
        return false;
    }

    // white pieces
    if (posColor[selX][selY] == FCC::PiecesColors::WHITE)
    {
        if (selY == 7) return true;
        return false;
    }

    // no piece at all
    return false;
}

void FCC::Chess::resetAllowedMovement()
{
    for (uint8_t i = 0; i <= 7; i++)
    {
        for (uint8_t j = 0; j <= 7; j++)
        {
            posPossible[i][j] = false;
        }
    }
}

bool FCC::Chess::checkIsPositionClear(uint8_t x, uint8_t y)
{
    if (posColor[x][y] == FCC::PiecesColors::NONE) return true;
    return false;
}

bool FCC::Chess::checkIsFriendlyOnField(uint8_t x, uint8_t y)
{
    if (posColor[x][y] == posColor[selX][selY]) return true;
    return false;
}

//void FCC::Chess::set_lang(FCC::Languages lang) {
//    m_lang = lang;
//}
