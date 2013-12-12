#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// ----------------------------------------------------------------------------
/** ----------------------------------------------------------------------------
File:		MasterMind.h
System:		MasterMind Test application
Component:	MasterMind main implementation
Author:		Habib Ahmed Qureshi
E-Mail:		habib.ahmed@gmail.com
Desc:		Header file for MasterMind
This file contains the main implementation for the game MasterMind.
Traditional Mastermind uses six different colors.
So I choose Red / Green / Blue / Orange / Yellow / Purple (R,G,B,O,Y,P) (also referred as color A,B,C,D,E,F)
Key pegs are defined as: B (Black = Correct position and color) & W (White = Correct color)
Reference: http://en.wikipedia.org/wiki/Mastermind_%28board_game%29
----------------------------------------------------------------------------
*/

class MasterMind
{
public:
	MasterMind()
	{
		memset(szKeyPegs, 0, sizeof szKeyPegs);
		memset(szSecretCode, 0, sizeof szSecretCode);
	};
	~MasterMind(){};

	//Randomly makes a secret code to be broken
	void CreateSecretCode();

	//Checks the guess and update the key pegs as a return value (ref input param).
	//Additionally indicates if the guess is correct or not as a return value.
	bool CheckTheGuess(string strGuess, string& strKeyPegs);

	//Publicly exposed constants
	const static int SECRET_SIZE = 4;
	const static int TOTAL_COLORS = 6;
	const static string AVAILABLE_CODE_PEGS;

private:
	//Creates the string to represent the key pegs in the string as represented by count and key_colo_char (B or W)
	string GetKeyPegs(int nCount, char cKeyColor)
	{
		string retVal = "";
		for (int i = 0; i < nCount; i++)
			retVal += cKeyColor;
		return retVal;
	}

	//Member variables
	char szSecretCode[SECRET_SIZE + 1];
	char szKeyPegs[SECRET_SIZE + 1]; //No need to keep history as the keypegs are displayed to the user.
};

#endif
