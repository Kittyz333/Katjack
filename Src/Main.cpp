#include <iostream>
#include "katjackfns.h"
#include <ctime>

int score = 500; // Ongoing player score
int cardval = 0;
int cardnum = 0;
int cardst = 0;
int loop = 0;
int gameround = 0;
int combinedhands = 0;
int act = 0;
int bet = 0;
int betcost = 0;
int gamescore = 0;
int syst = 1;
int msgr = 0;

int main()
{
	srand(time(0));

	while (syst = 1) {
		cout << "Loop: " << loop << " Round: " << gameround << "\n";

		Player P1;
		Player Dealer;

		do {
			gameround = 0;
			combinedhands = 0;
			act = 0;
			bet = 0;
			betcost = 0;
			gamescore = 0;


			Welcome();
			PlaceBet();
			cout << "Round: " << gameround << "\n";
			cout << "Let me deal you in.\n";
			cout << "Your first card is the ";
			CardCall();
			P1.HandUpdate();
			PrintCard(cardnum, cardst);
			cout << "\n";
			cout << "Your second card is the ";
			CardCall();
			P1.HandUpdate();
			PrintCard(cardnum, cardst);
			cout << "\n";
			cout << "Your hand total is: " << P1.hand << "\n\n";

			CardCall();
			Dealer.HandUpdate();
			CardCall();
			Dealer.HandUpdate();
			cout << "The dealer reveals their face-up card is the ";
			PrintCard(cardnum, cardst);
			cout << "Their hand value is " << Dealer.hand << "\n";
			P1.CheckBust();

			if (P1.bust == true) {
				cout << "Automatic bust! Try again!\n";
				GameScore(P1.hand, Dealer.hand);
				GameLoss();
				GameRepeat();
				loop = 0;
			}
			else {
				gameround++;
				loop++;
			}
		} while (gameround < 1);

		for (gameround == 1; gameround < 3; gameround++) { //Rewrite average round here.
			cout << loop;
			cout << "Round: " << gameround << "\n";
			P1.CheckBust();
			if (P1.bust == true) {
				cout << "You have busted! You must stand until this game ends.\n";
				act = 2;
			}
			else {
				Decision();
			}
			if (act == 1) {
				CardCall();
				P1.HandUpdate();
				cout << "You are dealt the ";
				PrintCard(cardnum, cardst);
				cout << "\n";
				cout << "Your hand total is: " << P1.hand << "\n";
			}
			else if (act == 2) {
				cout << "You have chosen to stand.\n";

			}
			else if (act == 3) {
				DoubleDown();
			}
			else if (act == 4) {
				cout << "You have folded!\n";
				ReturnBet();
				GameRepeat();
			}
			if (Dealer.hand < 17) { //Possibly rewrite to handle decision making in a separate player class for AI logic.
				CardCall();
				Dealer.HandUpdate();
				cout << "The dealer has drawn the ";
				PrintCard(cardnum, cardst);
			}
			else {
				cout << "The dealer has chosen to stand.\n";
			}
		}

		while (gameround == 3) { //This line should be good.
			cout << loop;
			P1.CheckBust();
			Dealer.CheckBust();
			cout << P1.bust << " dlr: " << Dealer.bust << "\n";
			if ((P1.bust == true && Dealer.bust == true) || P1.hand == Dealer.hand) {
				cout << "No one has won. Tie!\n";
				ReturnBet();
				GameRepeat();
			}
			else if (P1.bust == true) {
				cout << "Bust! Try again! \n";
				cout << "Player " << P1.bust << "Dealer " << Dealer.bust << "\n";
				GameLoss();
				GameScore(P1.hand, Dealer.hand);
				GameRepeat();
			}
			else if (Dealer.bust == true) {
				cout << "Dealer has bust! You win! \n";
				GameScore(P1.hand, Dealer.hand);
				GameWin();
				GameRepeat();
			}
			else if (P1.hand > Dealer.hand) {
				cout << "Your hand is closest to 21!\n";
				GameScore(P1.hand, Dealer.hand);
				GameWin();
				GameRepeat();
			}
			else if (P1.hand < Dealer.hand) {
				cout << "Dealer's hand is closer to 21! You have lost!\n";
				GameScore(P1.hand, Dealer.hand);
				GameLoss();
				GameRepeat();
			}
		}
	}

	return 0;
}