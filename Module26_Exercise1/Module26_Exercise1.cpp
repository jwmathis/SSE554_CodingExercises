// Module26_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	
	const string ROCK = u8"\U0001FAA8";
	const string PAPER = u8"\U0001F4C4";
	const string SCISSORS = u8"\u2702";
	cout << "Rock, Paper, Scissors" << endl;
	cout << "---------------------" << endl;
	cout << "1. " << ROCK << endl;
	cout << "2. " << PAPER << endl;
	cout << "3. " << SCISSORS << endl;

	srand(time(NULL));
	int userChoice = 0;
	cout << "Enter your choice (1-3)";
	cin >> userChoice;

	if (userChoice < 1 || userChoice > 3) {
		cout << "Invalid choice" << endl;
		return 1;
	}

	int computerChoice = rand() % 3 + 1;
	string userMove = (userChoice == 1) ? ROCK : (userChoice == 2) ? PAPER : SCISSORS;
	string computerMove = (computerChoice == 1) ? ROCK : (computerChoice == 2) ? PAPER : SCISSORS;

	cout << "You chose " << userMove << endl;
	cout << "The computer chose " << computerMove << endl;

	if (userChoice == computerChoice) {
		cout << "It's a tie" << endl;
	}
	else if ((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2)) {
		cout << "You win!" << endl;
	}
	else
	{
		cout << "Computer wins!" << endl;
	}
	return 0;
}
