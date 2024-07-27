using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

enum enGameChoice { Stone = 1, Paper = 2, ٍScissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3};

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To) {

	//Function to generate a random number

	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

enGameChoice ReadPlayer1Choice()
{
	short PlayerChoice = 1;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissor ? ";
		cin >> PlayerChoice;

		while (cin.fail())
		{
			//user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a valid one: " << endl;
			cin >> PlayerChoice;
		}

	} while (PlayerChoice < 1 || PlayerChoice >3);

	return (enGameChoice)PlayerChoice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice) RandomNumber(1,3);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::ٍScissors)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::ٍScissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;
	}

	//If you reach here then Player1 is the Winner
	return enWinner::Player1;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1","Computer","No Winner" };
	return arrWinnerName[Winner - 1];
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone","Paper","Scissor" };

	return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case Player1:
		system("color 27"); //turn screen to Green
		break;
	case Computer:
		system("color 47"); //turn screen to Red
		cout << "\a";
		break;
	case Draw:
		system("color 67"); //turn screen to Yellow
		break;
	default:
		break;
	}

}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n__________Round [" << RoundInfo.RoundNumber << "]___________\n\n";

	cout << "Player1 Choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : " << RoundInfo.WinnerName << endl;

	cout << "______________________________" << endl;

	SetWinnerScreenColor(RoundInfo.Winner);


}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResults FillGameResults(short GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes) 
{
	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes,ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

string Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + '\t';
		cout << t;
	}
	return t;	
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] Begin :\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		//Increase Win/Draw Counters
		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds,Player1WinTimes,ComputerWinTimes,DrawTimes);
}

short ReadHowManyRounds() {

	short rounds = 1;
	do
	{
		cout << "How Many Rounds 1 to 10?" << endl;
		cin >> rounds;

		while (cin.fail())
		{
			//user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a valid one: " << endl;
			cin >> rounds;
		}

	} while (rounds < 1 || rounds > 10);

	return rounds;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "+++ G a m e   O v e r +++\n";
	cout << Tabs(2) << "__________________________________________________________\n\n";

}

void ShowFinalGameResult(stGameResults GameResults)
{
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 won times  : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "__________________________________________________________\n\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}

void ResetScreen() 
{
	system("cls");
	system("color 07");
}

void StartGame() 
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResult(GameResults);

		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	StartGame();
}