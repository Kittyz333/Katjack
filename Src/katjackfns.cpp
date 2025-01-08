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

}

void Round() { //Ew. Okay. So, in this one, we handle a round loop that calls Decision, but I believe I should be handling this differently.

	 // Replace with the class method properly.
}

int Decision() { // Asks what if you'd like to hit, stand, etc, and performs the trigger. ((Dealer currently forced to draw here.))

	cout << "What would you like to do?\n";
	cout << "1. Hit 2. Stand\n";
	cout << "3. Double Down 4. Fold\n";
		cin >> act;
		return act;
}

void DealerDecision() { //Dealer makes their choice, error possibly here?

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
		else {
			return 0;
		}
}

int GameWin() { //Twin of GameLoss.
	int currentwin = (gamescore * bet) + betcost;
	score = score + currentwin;
	cout << "You have won " << currentwin << " coins because of your bet of " << betcost << " coins!\n";
	cout << "You now have " << score << " coins.\n";
	cout << "The combined hand total was: " << combinedhands << ". The game score was: " << gamescore << ".\n";
	return score;
}

int GameLoss() { //Twin of GameWin. Calls GameScore to access necessary variables to print, clears board and returns the score. 
	int currentloss = gamescore;
	score = score - currentloss;
	currentloss = currentloss + betcost;
	cout << "You have lost " << currentloss << " coins because of your bet of " << betcost << " coins.\n";
	cout << "You now have " << score << " coins.\n";
	cout << "The combined hand total was: " << combinedhands << " The game score was: " << gamescore << "\n";
	return score;
}

int GameScore(int hand1, int hand2) { //Returns combinedhands and gamescore for end of game print.
	combinedhands = hand1 + hand2; //Change this to take the values of the player and dealer object's hands.
	gamescore = combinedhands * 3;
	return combinedhands, gamescore;
}

int ReturnBet() { //Halves the bet paid and returns it to player in the event of tie or fold.
	int rtrnbet = betcost / 2;
	score = score + rtrnbet;
	cout << "You have been returned " << rtrnbet << " coins back from your bet.\n";
	cout << "You now have " << score << " coins.\n";
	return score;
}

int ResetScores() { //Resets all scores (except running player score). Error in loop definitely here.
	combinedhands = 0; //Possibly reset with loop and others somehow.
	gamescore = 0;
	bet = 0; //Possibly reset separate from loop and gameround, or with.
	betcost = 0;
	gameround = 0; //Reset this, loop and act somewhere safely.
	loop = 0;
	act = 0;
	return act, combinedhands, gamescore, bet, betcost, gameround, loop;
}

int DoubleDown() {
	bet = bet * 2;
	score = score - betcost;
	cout << "You have doubled down your bet of " << betcost << ".\n";
	betcost = betcost + betcost;
	cout << "You have bet a total of " << betcost << " on this hand.\n";
	return score, betcost, bet;
}

void Welcome() {
	int msggen = 1 + (rand() % 5);

	if (msgr = 0) {
		cout << "Welcome to Katjack!\n"; //Possibly make this have options: 1. Play Alone 2. Play Together 3. Read Rules 4. Change Decks
	}

	else if (msgr = 1) { //Winning return messages
		switch (msggen) {
		case 1:
			cout << "Great job! Let's play again.\n";
			break;
		case 2:
			cout << "Keep it up! New game!\n";
			break;
		case 3:
			cout << "That was good! let's try another!\n";
			break;
		case 4:
			cout << "Another one, another one!\n";
			break;
		case 5:
			cout << "Let's keep playing!\n";
			break;
		}

	}

	else if (msgr = 2) { //Losing return messages
		switch (msggen) {
		case 1:
			cout << "Better like this time.\n";
			break;
		case 2:
			cout << "Maybe next time...\n";
			break;
		case 3:
			cout << "So close! Let's try again.\n";
			break;
		case 4:
			cout << "Don't give up now!\n";
			break;
		case 5:
			cout << "We all have our days.\n";
			break;

		}
	}
}