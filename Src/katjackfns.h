#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

extern int cardval;
extern int cardnum;
extern int cardst;
extern int plhand;
extern int ophand;
extern int combinedhands;
extern int act;
extern int score;
extern int loop;
extern int gameround;
extern int gamescore;
extern int bet;
extern int betcost;
extern bool plbust;
extern bool dlrbust;

void RoundStart();

int NewRound();

void Round();

int CardCall();

void PrintCard(int cardnum, int cardst);

int HandUpdate();

int DealerUpdate();

void DealerDecision();

void Decision();

int GameRepeat();

int GameWin();

int GameLoss();

int ReturnBet();

int PlaceBet();

int GameScore();

int ResetScores();

int DoubleDown();

bool CheckBust();

bool DlrCheckBust();

int RoundRestart();