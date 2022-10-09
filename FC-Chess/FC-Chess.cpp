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
        for (int j = 0; i < 2; i++) {
            posColor[i][j] = PiecesColors::BLACK;
        }
        for (int j = 6; i < 8; i++) {
            posColor[i][j] = PiecesColors::WHITE;
        }
        for (int j = 2; i < 7; i++) {
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

bool FCC::Chess::checkIsEnemyOnField(uint8_t* x, uint8_t* y)
{
    // Check if the selected piece/field unequals the target piece/field => is true then
    if (posColor[*x][*y] != posColor[selX][selY])
    {
        return true;
    }
    return false;
}

bool FCC::Chess::checkPosInBounds(uint8_t* x, uint8_t* y)
{
    // check if X and Y values are below 8. No negative values have to be checked since the var type is unsigned int
    if (*x <= 7 && *y <= 7)
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
    for (uint8_t i = selX; i <= 7; i++)
    {
        if (checkIsEnemyOnField(&i, &selY)) break;
        posPossible[i][selY] = true;
    }
    for (uint8_t i = selX; i >= 0; i--)
    {
        if (checkIsEnemyOnField(&i, &selY)) break;
        posPossible[i][selY] = true;
    }
}

void FCC::Chess::checkMovesVertical()
{
    for (uint8_t i = selY; i <= 7; i++)
    {
        if (checkIsEnemyOnField(&selX, &i)) break;
        posPossible[selX][i] = true;
    }
    for (uint8_t i = selY; i >= 0; i--)
    {
        if (checkIsEnemyOnField(&selX, &i)) break;
        posPossible[selX][i] = true;
    }
}

//void FCC::Chess::set_lang(FCC::Languages lang) {
//    m_lang = lang;
//}
