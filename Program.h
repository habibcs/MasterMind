#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include "MasterMind.h"

using namespace std;

/** ----------------------------------------------------------------------------
File:		Program.h
System:		MasterMind Test application
Component:	Driver class
Author:		Habib Ahmed Qureshi
E-Mail:		habib.ahmed@gmail.com
Desc:		Used as a driver class to control the whole program execution
----------------------------------------------------------------------------
*/

class Program
{
public:
	Program(){};
	~Program(){};

	const static int TOTAL_GAMES = 10;
	const static int TOTAL_TRIES = 12;
	const static int MAX_SCORE_IN_A_SINGLE_GAME = 12;

	//Displays Intro
	void Intro()
	{
		cout << "** Welcome to the (simple) MasterMind game **\n\nWe shall play 10 games to decide the winner."<<endl;
		cout << "Let me start as a Codemaker and you (human) as a codebreaker.\nYou have 12 guesses to find the right secret."
			" Each wrong guess will give me 1 point and the correct guess will give you 12.\n"
			"Let's begin!\n" << endl;
	}
	//Plays the game
	void Play();

private:
	//Takes the input from the user, restricts it to 4 (SECRET_SIZE) chars
	string TakeInput(int nGuessNo);
	inline void PrintGameStatus(int nGame, int nHumanScore, int nComputerScore)
	{
		cout << "Game: " << nGame << " You:" << nHumanScore << " Computer: " << nComputerScore << endl;
	}

	//Member variables
	MasterMind m_mm; //mmm.. :)

	//Constants
	const static string BEGIN_GAME_LVL_MSG;
	const static string NEXT_GAME_LVL_MSG;
	const static string SUCCESS_GAME_LVL_MSG;
};

#endif
