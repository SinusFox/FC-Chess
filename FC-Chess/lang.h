#pragma once
#include <iostream>
#include <string>

namespace FCC
{
	class Lang
	{
		public:
			// texts shown in gui/tui
			std::string menuButtonPlay = "Start Game!";
			std::string menuButtonSettings = "Settings";
			std::string menuButtonCredits = "Credits";
			std::string menuButtonExitGame = "Exit to Desktop";
			std::string error = "An error occoured. The game will exit now.";
			std::string gameForbiddenMove = "This move is not allowed.";
			std::string credits = "FoxCreation Chess by SinusFox 2022.\nContact: admiralemser@gmail.com\nhttps://github.com/AdmiralEmser/FC-Chess";
			std::string backButton = "Back <--";
	};
}