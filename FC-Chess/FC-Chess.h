#pragma once
//#include <iostream>
// #include "tui.h"
#include "lang.h"

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
    class TUI
    {
        /* Why is FCC::TUI here and not in tui.h, so another file? Well, that's quite easy. MSVC doesn't know how to access code from other files, apparently.
        Error code is that class FCC::TUI wouldn't be a member of namespace FCC - which is a wrong statement. It is a member of FCC. 
        So yeah, thanks Microsoft.*/

        public:
            // constructor and destructor
            TUI() = default;
            virtual ~TUI() = default;

            // funcs
            void startup();
            void mainLoop();
            void testLoop();
    };
    
    class Chess
    {
        public:
            // constructor and destructor
            Chess();
            virtual ~Chess() = default;

            // vars
            uint8_t posPieces[8][8], posColor[8][8], posPossible[8][8], selX, selY, tarX, tarY;     //tar = target, sel = selected, pos = possible
            
            // funcs
            void mainMenu();
            void startupGame();
            void gameLoop();
            void checkHorizontalMovementAllowed();
            void checkVerticalMovementAllowed();
            void checkDiagonalMovementAllowed();
            //void set_lang(FCC::Languages lang);
            
        private:
            // vars
            bool gameEnded;

            // texts for tui and gui
            FCC::Lang lang;
            FCC::TUI tui;
            //FCC::ChessLang chessLangObj;
            //FCC::Languages m_lang{ FCC::Languages::ENGLISH };

            // funcs
            void input();
            bool checkIsEnemyOnField();
            bool checkSelectedPosInBounds();
            bool checkTargetPosInBounds();
            void resetFieldColors();
    };
}
