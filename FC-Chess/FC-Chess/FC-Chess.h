#pragma once
#include <iostream>

#include "graphics.h"

namespace FCC
{
    // vars
    enum class Pieces {
        NONE,
        PAWN,
        ROOK,
        BISHOP,
        KNIGHT,
        QUEEN,
        KING
    };
    enum class PiecesColors {
        NONE,
        BLACK = 10,
        WHITE = 20
    };
    
    // classes and funcs
    class Chess
    {
        public:
            // constructor and destructor
            Chess() = default;
            ~Chess() = default;

            // vars
            uint8_t posPieces[8][8], posColor[8][8], posPossible[8][8];
            
            // funcs
            void mainLoop();
        private:
            bool gameEnded;
    };
}
