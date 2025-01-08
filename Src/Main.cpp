#include <iostream>
#include "katjackfns.h"
#include <ctime>

int loop = 0;
int gameround = 0;
int score = 500; // Ongoing player score
int plhand = 0; //Player total card value
int ophand = 0; //Opponent/dealer total card value
int combinedhands;
int cardval = 0;
int cardnum;
int cardst;
int act = 0;
int bet;
int betcost;
int gamescore;
bool plbust = false;
bool dlrbust = false;

int main()
{

	cout << "Loop: " << loop << " Round: " << gameround;
	srand(time(0));


	do {
		cout << "Welcome to Katjack.\n";
		PlaceBet();
		RoundStart();
		CheckBust();
		if (plbust == true) {
			cout << "Automatic bust! Try again!\n";
			GameLoss();
			GameRepeat();
			ResetScores();
		}
		else {
			gameround++;
			loop++;
		}
	} while (loop < 1);

	for (gameround == 1; gameround < 3; gameround++) {
		cout << loop;
		Round();
		CheckBust();
		if (plbust == true) {
			cout << "Bust! Try again! \n";
			GameLoss();
			GameRepeat();
			ResetScores();
		}
	}

	while (gameround == 3) {
		cout << loop;
		CheckBust();
		DlrCheckBust();
		cout << plbust << " dlr: " << dlrbust << "\n";
		if ((plbust == true && dlrbust == true) || plhand == ophand) {
			cout << "No one has won. Tie!\n";
			ReturnBet();
			GameRepeat();
			ResetScores();
		}
		else if (plbust == true) {
			cout << "Bust! Try again! \n";
			cout << "Player " << plbust << "Dealer " << dlrbust << "\n";
			GameLoss();
			GameRepeat();
			ResetScores();
		}
		else if (dlrbust == true) {
			cout << "Dealer has bust! You win! \n";
			GameWin();
			GameRepeat();
			ResetScores();
		}
		else if (plhand > ophand) {
			cout << "Your hand is closest to 21!\n";
			GameWin();
			GameRepeat();
			ResetScores();
		}
		else if (plhand < ophand) {
			cout << "Dealer's hand is closer to 21! You have lost!\n";
			GameLoss();
			GameRepeat();
			ResetScores();
		}
	}

	return 0;
}