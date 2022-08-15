#include "fc-chess.h"

void FCC::Chess::mainLoop()
{
    FCC::ChessTUI tui;

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

    // main loop
    while(!gameEnded) {

        tui.mainLoop();
    }
    
    
}