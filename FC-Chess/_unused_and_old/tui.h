#pragma once
#include "FC-Chess.h"

namespace FCC
{
    class TUI
    {
        public:
            // constructor and destructor
            TUI() = default;
            virtual ~TUI() = default;

            // funcs
            void startup();
            void mainLoop();
            void testLoop();
    };
}