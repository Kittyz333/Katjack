#include <iostream>
#include <string>
#include "katjackfns.h"
#include <ctime>

int CardCall() {
	int cardgen = 1 + (rand() % 52);

	if (cardgen < 14) {
		cardst = 0;
		cardval = cardgen;
	}
	else if (cardgen > 13 && cardgen < 27) {
		cardst = 1;
		cardval = cardgen - 13;
	}
	else if (cardgen > 26 && cardgen < 40) {
		cardst = 2;
		cardval = cardgen - 26;
	}
	else if (cardgen > 39 && cardgen < 53) {
		cardst = 3;
		cardval = cardgen - 39;
	}
	cardnum = cardval - 1;
	return cardval, cardnum, cardst;
}

void PrintCard(int cardface, int cardsuit) {
	string cards[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", };
	string suits[4] = { "of Clubs", "of Diamonds", "of Hearts", "Of Spades" };
	cout << cards[cardface] << " " << suits[cardsuit] << "\n";
}

int PlaceBet() { // Informs current coins, 
	cout << "You currently have " << score << " coins.\n";
	cout << "Would you like to place a bet? \n";
	cout << "1. Standard (100) 2. Double (200)\n";
	cout << "3. Triple (300) 4. 10x Multiplier!!!! (1000)\n";
	cin >> act;
	if (act == 4) {
		bet = 10;
	}
	else {
		bet = act;
	}
	betcost = bet * 100;

	if (betcost > score) {
		cout << "Bet too high! Try again!\n";
		PlaceBet();
	}
	else {
		score = score - betcost;
		cout << "You have placed a bet of " << betcost << ". You have " << score << " coins remaining.\n";
	}
	return score, bet, betcost;
}
void RoundStart() {
	cout << "Round: " << gameround << "\n";
	cout << "Let me deal you in.\n";
	cout << "Your first card is the ";
	CardCall();
	HandUpdate();
	PrintCard(cardnum, cardst);
	cout << "\n";
	cout << "Your second card is the ";
	CardCall();
	HandUpdate();
	PrintCard(cardnum, cardst);
	cout << "\n";
	cout << "Your hand total is: " << plhand << "\n\n";

	CardCall();
	DealerUpdate();
	CardCall();
	DealerUpdate();
	cout << "The dealer reveals their face-up card is the ";
	PrintCard(cardnum, cardst);
	cout << "Their hand value is " << ophand << "\n";
}

int NewRound() {
	gameround++;
    return gameround;
}

void Round() { //Ew. Okay. So, in this one, we handle a round loop that calls Decision, but I believe I should be handling this differently.

		cout << "Round: " << gameround << "\n";
		Decision();
		DealerDecision();
}

int HandUpdate() { //The update for the player's hand. ((Removed win condition article.))
	    plhand = plhand + cardval;
		return plhand;
}

int DealerUpdate() { //The update for the dealer's hand. ((Removed win condition article.))
		ophand = ophand + cardval;
		return ophand;
}

bool CheckBust() {
	if (plhand > 21) {
		plbust = true;
	}
	else {
		plbust = false;
	}
	return plbust;
}
bool DlrCheckBust() {
	if (ophand > 21) {
		dlrbust = true;
	}
	else {
		dlrbust = false;
	}
	return dlrbust;
}

void Decision() { // Asks what if you'd like to hit, stand, etc, and performs the trigger. ((Dealer currently forced to draw here.))

	cout << "What would you like to do?\n";
	cout << "1. Hit 2. Stand\n";
	cout << "3. Double Down 4. Fold\n";
		cin >> act;
		if (act == 1) {
			CardCall();
			HandUpdate();
			cout << "You are dealt the";
			PrintCard(cardnum, cardst);
			cout << "\n";
			cout << "Your hand total is: " << plhand << "\n";
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
}

void DealerDecision() { //Dealer makes their choice, error possibly here?
	if (ophand < 17) {
		CardCall();
		DealerUpdate();
		cout << "The dealer has drawn the ";
		PrintCard(cardnum, cardst);
	}
	else {
		cout << "The dealer has chosen to stand.\n";
	}
}
int GameRepeat() { //Asks if player would like to start a new game or close.
	cout << "What would you like to do?\n";
		cout << "1. Next Round 2. Close\n";
		cin >> act;
	if (act == 1) { //Find a way to restart game properly.
		system("cls");
		gameround = 0;
		return gameround;
	}
}

int GameWin() { //Twin of GameLoss.
	GameScore();
	int currentwin = (gamescore * bet) + betcost;
	score = score + currentwin;
	cout << "You have won " << currentwin << " coins because of your bet of " << betcost << " coins!\n";
	cout << "You now have " << score << " coins.\n";
	cout << "The combined hand total was: " << combinedhands << ". The game score was: " << gamescore << ".\n";
	return score, gamescore;
}

int GameLoss() { //Twin of GameWin. Calls GameScore to access necessary variables to print, clears board and returns the score. 
	GameScore();
	int currentloss = gamescore;
	score = score - currentloss;
	currentloss = currentloss + betcost;
	cout << "You have lost " << currentloss << " coins because of your bet of " << betcost << " coins.\n";
	cout << "You now have " << score << " coins.\n";
	cout << "The combined hand total was: " << combinedhands << " The game score was: " << gamescore << "\n";
	return score;
}

int ReturnBet() { //Halves the bet paid and returns it to player in the event of tie or fold.
	int rtrnbet = betcost / 2;
	score = score + rtrnbet;
	cout << "You have been returned " << rtrnbet << " coins back from your bet.\n";
	cout << "You now have " << score << " coins.\n";
	return score;
}

int GameScore() { //Returns combinedhands and gamescore for end of game print.
	combinedhands = plhand + ophand;
	gamescore = combinedhands * 3;
	return combinedhands, gamescore;
}

int ResetScores() { //Resets all scores (except running player score).
	act = 0;
	combinedhands = 0;
	gamescore = 0;
	plhand = 0;
	ophand = 0;
	bet = 0;
	betcost = 0;
	gameround = 0;
	loop = 0;
	plbust = false;
	dlrbust = false;
	return act, combinedhands, gamescore, plhand, ophand, bet, betcost, gameround, loop;
}

int DoubleDown() {
	bet = bet * 2;
	score = score - betcost;
	cout << "You have doubled down your bet of " << betcost << ".\n";
	betcost = betcost + betcost;
	cout << "You have bet a total of " << betcost << " on this hand.\n";
	return score, betcost;
}

int RoundRestart() {
	gameround = 0;
		return gameround;
}