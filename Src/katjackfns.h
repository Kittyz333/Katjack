#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

extern int cardval;
extern int cardnum;
extern int cardst;
extern int combinedhands;
extern int act;
extern int score;
extern int loop;
extern int gameround;
extern int gamescore;
extern int bet;
extern int betcost;
extern int msgr;


class Player {
public:

	int hand;
	bool bust;

	Player() {
		hand = 0;
		bust = false;
	}

	int HandUpdate() { //Adds value of drawn card to hand.
		hand = hand + cardval;
		return hand;
	}

	bool CheckBust() {
		if (hand > 21) {
			bust = true;
		}
		else {
			bust = false;
		}
		return bust;
	}

};

void RoundStart();

void Round();

int CardCall();

void PrintCard(int cardnum, int cardst);

void DealerDecision();

int Decision();

int GameRepeat();

int GameWin();

int GameLoss();

int ReturnBet();

int PlaceBet();

int ResetScores();

int DoubleDown();

int GameScore(int hand1, int hand2);

void Welcome(int msgr);