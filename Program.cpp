#include "Program.h"
#include <algorithm>

using namespace std;

const string Program::BEGIN_GAME_LVL_MSG = "Making the secret code... Done.\nNow you try to break the code.. so make your first guess!";
const string Program::NEXT_GAME_LVL_MSG = "\nLet's play the next game.";
const string Program::SUCCESS_GAME_LVL_MSG = "Congratulations! Your guess was correct";

string Program::TakeInput(int nGuessNo)
{
	string strInput;
	string strINPUT_ERR_MSG = "Input should be of 4 uppercase letters like: RGBO (Allowed: RGBOYP)";

Input_Again:
	cout << "Take your guess no " << nGuessNo << " (Options:RGBYOP): ";
	cin >> strInput;

	if (strInput.length() != m_mm.SECRET_SIZE)
	{
		cout << strINPUT_ERR_MSG << endl;
		goto Input_Again;
	}
	std::transform(strInput.begin(), strInput.end(), strInput.begin(), ::toupper); //Make all as Uppercase

	//If a character is used which is not permissible, ask for input again.
	for (int i = 0; i < m_mm.SECRET_SIZE; i++)
	{
		if (m_mm.AVAILABLE_CODE_PEGS.find(strInput[i]) == string::npos)
		{
			cout << strINPUT_ERR_MSG << endl;
			goto Input_Again;
		}
	}

	//For now I am not putting checks for only permissible characters i.e RGBOYP
	return strInput;
}

void Program::Play()
{
	int nComputerScore = 0;
	int nHumanScore = 0;
	string strGuess;
	string strKeyPegs;

	for (int nGame = 0; nGame < TOTAL_GAMES; nGame++)
	{
		cout << BEGIN_GAME_LVL_MSG << endl;
		m_mm.CreateSecretCode();

		for (int t = 0; t < TOTAL_TRIES; t++)
		{
			strGuess = TakeInput(t + 1);
			if (m_mm.CheckTheGuess(strGuess, strKeyPegs))
			{
				cout << SUCCESS_GAME_LVL_MSG << endl;
				nHumanScore += MAX_SCORE_IN_A_SINGLE_GAME;
				PrintGameStatus(nGame + 1, nHumanScore, nComputerScore);
				break;
			}
			else
			{
				nComputerScore++;
				cout << "Key pegs: " << strKeyPegs << endl;
				PrintGameStatus(nGame + 1, nHumanScore, nComputerScore);
			}
		}

		cout << NEXT_GAME_LVL_MSG << endl;
	}
}
