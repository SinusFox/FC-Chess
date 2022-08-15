// FC-Chess.cpp : Defines the entry point for the application.
//

#include "fc-chess.h"

//using namespace std;

int main()
{
	FCC::Chess gm;
	gm.mainLoop();

	FCC::ChessTUI test;
	test.testLoop();

	return 0;
}
