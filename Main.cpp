#include <iostream>
#include <string>
#include "FBullCowGame.h"

FBullCowGame BCGame;

int main()
{
	do
	{
		BCGame.PlayGame();
	} while (BCGame.AskToPlayAgain());
	return 0;
}

