#pragma once
#include <iostream>
//#include "FC-Chess.h"
#include <string>

namespace FCC {
	enum class Languages {
		ENGLISH,
		GERMAN
	};
}
namespace FCC::ChessLang
{
	inline std::string testString(FCC::Languages lang) {
		switch (lang) {
		case FCC::Languages::ENGLISH:
			return "Hello World";
		case FCC::Languages::GERMAN:
			return "Hallo Welt";
		}
	}
}