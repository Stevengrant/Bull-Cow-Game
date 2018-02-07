#include <iostream>
#include <string>
#include "FBullCowGame.h"
FBullCowGame BCGame;
int main()
{
	do
	{
		BCGame.PlayGame();
		//TODO add game summary
	} while (BCGame.AskToPlayAgain());
	return 0;
}

