// #include "tui.h"
#include "FC-Chess.h"

void FCC::TUI::startup()
{

}

void FCC::TUI::mainLoop()
{
    
}

void FCC::TUI::testLoop()
{
    std::cout << "\u2654" << std::endl;
    std::cout << "♔" << std::endl;
    //std::cout << L"♔";
}

void FCC::TUI::errOutput(std::string* errMessage)
{
    std::cout << *errMessage;
}
