#include <iostream>
#include <string>
#include "FBullCowGame.h"
//using namespace std;
void PrintIntro();
void PlayGame();
void HandleGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;

std::string GetGuess();
std::string Guess;
int main()
{
	PrintIntro();
	do
	{
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}

//Introduce Game
void PrintIntro()
{
	constexpr int W_LENGTH = 5;
	std::cout << "Welcome to BULLS AND COWS\n";
	std::cout << "can you get the " << W_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

void HandleGuess() {
	BCGame.UpdateTrys();
	std::cout << "you guessed: " << Guess << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "do you want to play again? (y/n) ";
	std::string res;
	std::getline(std::cin, res);
	return (toupper(res[0]) == 'Y');
}

//Get guess from player.
std::string GetGuess() {
	std::cout << "Try "<< BCGame.GetCurrentTry() << ". Make a guess!\n";
	std::getline(std::cin, Guess);
	HandleGuess();
	return Guess;
}
//asdf
void PlayGame()
{
	for (int i = 0; i < BCGame.GetMaxTries(); i++)
	{
		GetGuess();
		std::cout << std::endl;
	}
}