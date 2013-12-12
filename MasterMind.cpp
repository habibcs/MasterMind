#include "MasterMind.h"

const string MasterMind::AVAILABLE_CODE_PEGS = "RGBOYP";

void MasterMind::CreateSecretCode()
{
	//Initialize random seed
	srand((unsigned int)time(NULL));

	szSecretCode[0] = AVAILABLE_CODE_PEGS[rand() % 6]; //Duplicates are allowed. T:GRPG
	szSecretCode[1] = AVAILABLE_CODE_PEGS[rand() % 6];
	szSecretCode[2] = AVAILABLE_CODE_PEGS[rand() % 6];
	szSecretCode[3] = AVAILABLE_CODE_PEGS[rand() % 6];
	szSecretCode[4] = '\0';
};

bool MasterMind::CheckTheGuess(string strGuess, string& strKeyPegs)
{
	if (strGuess.compare(szSecretCode) == 0)
	{
		strKeyPegs = "BBBB";
		return true; //Your guess is correct!
	}

	//*B* = Correct position and color pegs
	//*W* = Correct color pegs
	strKeyPegs = "";
	int cj;
	for (int i = 0; i < SECRET_SIZE; i++)
	{
		cj = -1;
		for (int j = 0; j < SECRET_SIZE; j++)
		{
			if (szSecretCode[i] == strGuess[j])
			{
				if (i == j)
				{
					strKeyPegs += 'B';
					strGuess[j] = 'X';
					cj = -1; //we found match on exact position so forget the older one and check next peg
					break;
				}
				if (j < i)
					cj = j; //cache the j
				else if (j > i)
				{
					if (szSecretCode[j] == strGuess[j]) //look ahead (shortcut - peek ahead) in case position match also there
						strKeyPegs += 'B';
					else strKeyPegs += 'W';
					strGuess[j] = 'X';
					cj = -1; //we found another match ahead so forget the older one and check next peg
					break;
				}
			}
		}
		if (cj != -1)
		{
			strKeyPegs += 'W';
			strGuess[cj] = 'X';
		}
	}
	std::sort(strKeyPegs.begin(), strKeyPegs.end());
	return false;
}
