#include "FC-Chess.h"

FCC::Chess::Chess()
{

    //start game
    FCC::Chess::startup();
    FCC::Chess::mainLoop();
}

void FCC::Chess::mainLoop()
{
    // initialize user interface
    
    // tui.startup();

    // main loop
    while(!gameEnded)
    {
        /*MISSING: user input*/
        // tui.mainLoop();
    }
}

void FCC::Chess::startup()
{
    // preparing board: colors
    for (int8_t i = 0; i < 8; i++) {
        for (int j = 0; i < 2; i++) {
            posColor[i][j] = (uint8_t)(PiecesColors::BLACK);
        }
        for (int j = 6; i < 8; i++) {
            posColor[i][j] = (uint8_t)(PiecesColors::WHITE);
        }
        for (int j = 2; i < 7; i++) {
            posColor[i][j] = (uint8_t)(PiecesColors::NONE);
        }
    }
    // preparing board: pieces
    for (int8_t i = 0; i < 8; i++) {
        posPieces[1][i] = (uint8_t)(Pieces::PAWN);
        posPieces[6][i] = (uint8_t)(Pieces::PAWN);
    }
    for (int8_t i = 0; i < 2; i++) {
        posPieces[i][0] = (uint8_t)(Pieces::ROOK);
        posPieces[i][7] = (uint8_t)(Pieces::ROOK);
        posPieces[i][1] = (uint8_t)(Pieces::KNIGHT);
        posPieces[i][6] = (uint8_t)(Pieces::KNIGHT);
        posPieces[i][2] = (uint8_t)(Pieces::BISHOP);
        posPieces[i][5] = (uint8_t)(Pieces::BISHOP);
        posPieces[i][3] = (uint8_t)(Pieces::KING);
        posPieces[i][4] = (uint8_t)(Pieces::QUEEN);
    }

    // set language to English (default)
    // m_lang = FCC::Languages::ENGLISH;
}

bool FCC::Chess::checkIsEnemyOnField()
{
    // Check if the selected piece/field unequals the target piece/field => is true then
    if (posColor[selX][selY] != posColor[tarX][tarY])
    {
        return true;
    }
    return false;
}

bool FCC::Chess::checkSelectedPosInBounds()
{
    // check if X and Y values are below 8. No negative values have to be checked since the var type is unsigned int
    if (selX <= 7 && selX <= 7)
    {
        return true;
    }
    return false;
}

bool FCC::Chess::checkTargetPosInBounds()
{
    // check if X and Y values are below 8. No negative values have to be checked since the var type is unsigned int
    if (tarX <= 7 && tarX <= 7)
    {
        return true;
    }
    return false;
}

//void FCC::Chess::set_lang(FCC::Languages lang) {
//    m_lang = lang;
//}
