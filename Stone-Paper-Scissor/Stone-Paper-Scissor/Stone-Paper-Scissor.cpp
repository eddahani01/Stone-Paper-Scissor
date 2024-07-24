using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>



struct stGameResults
{
	int Rounds = 0;
	int PlayerWins = 0;
	int ComputerWins = 0;
	int DrawTimes = 0;
	string FinalWinner = "";
};

int RandomNumber(int From, int To) {

	//Function to generate a random number

	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

short ReadHowManyRounds() {
	
	int rounds = 0;
	do
	{
		cout << "How Many Rounds 1 to 10?" << endl;
		cin >> rounds;
	} while (rounds < 1 || rounds > 10);

	return rounds;
}

void GameOverScreen(stGameResults stGameResult) {


	cout << "\t\t\t________________________________________\n";
	cout << "\n\t\t\t\t+++ G a m e   O v e r +++\n";
	cout << "\t\t\t________________________________________\n\n";
	cout << "\t\t\t_____________[Game Result]______________\n\n";
	cout << "\t\t\tGame Rounds\t\t" << ": " << stGameResult.Rounds<<endl;
	cout << "\t\t\tPlayer won times\t" << ": " << stGameResult.PlayerWins << endl;
	cout << "\t\t\tComputer won times\t" << ": " << stGameResult.ComputerWins << endl;
	cout << "\t\t\tDraw times\t\t" << ": " << stGameResult.DrawTimes << endl;
	cout << "\t\t\tFinal Winner\t\t" << ": " << stGameResult.FinalWinner << endl;
	cout << "\t\t\t_______________________________________\n";
	
	


}


void StartTheGame() {
	system("cls");
	system("color 07");


	int rounds = ReadHowManyRounds();
	int PlayerChoice = 0;
	int ComputerChoice = 0;

	int PlayerWins = 0;
	int ComputerWins = 0;
	int DrawTimes = 0;

	stGameResults stGameresult;

	for (int i = 1; i <= rounds; i++)
	{

		cout << "\nRound [" << i << "] Begin :" << endl;
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissor ? ";
		cin >> PlayerChoice;
		ComputerChoice = RandomNumber(1, 3);

		cout << "\n__________Round [" << i << "]___________" << endl;

		if (PlayerChoice == 1 && ComputerChoice == 2)
		{
			cout << "\nPlayer1 Choice: Stone" << endl;
			cout << "Computer Choice: Paper" << endl;
			cout << "Round Winner : [Computer]" << endl;
			system("color 47");
			cout << '\a';
			ComputerWins++;
		}
		else if (PlayerChoice == 1 && ComputerChoice == 3)
		{
			cout << "\nPlayer1 Choice: Stone" << endl;
			cout << "Computer Choice: Scissor" << endl;
			cout << "Round Winner : [Player1]" << endl;
			system("color 27");
			PlayerWins++;
		}
		else if (PlayerChoice == 1 && ComputerChoice == 1)
		{
			cout << "\nPlayer1 Choice: Stone" << endl;
			cout << "Computer Choice: Stone" << endl;
			cout << "Round Winner : [No Winner]" << endl;
			system("color 67");
			DrawTimes++;
		}
		else if (PlayerChoice == 2 && ComputerChoice == 3)
		{
			cout << "\nPlayer1 Choice: Paper" << endl;
			cout << "Computer Choice: Scissor" << endl;
			cout << "Round Winner : [Computer]" << endl;
			system("color 47");
			cout << '\a';
			ComputerWins++;

		}
		else if (PlayerChoice == 2 && ComputerChoice == 1)
		{
			cout << "\nPlayer1 Choice: Paper" << endl;
			cout << "Computer Choice: Stone" << endl;
			cout << "Round Winner : [Player1]" << endl;
			system("color 27");
			PlayerWins++;

		}
		else if (PlayerChoice == 2 && ComputerChoice == 2)
		{
			cout << "\nPlayer1 Choice: Paper" << endl;
			cout << "Computer Choice: Paper" << endl;
			cout << "Round Winner : [No Winner]" << endl;
			system("color 67");
			DrawTimes++;

		}
		else if (PlayerChoice == 3 && ComputerChoice == 1)
		{
			cout << "\nPlayer1 Choice: Scissor" << endl;
			cout << "Computer Choice: Stone" << endl;
			cout << "Round Winner : [Computer]" << endl;
			system("color 47");
			cout << '\a';
			ComputerWins++;

		}
		else if (PlayerChoice == 3 && ComputerChoice == 2)
		{
			cout << "\nPlayer1 Choice: Scissor" << endl;
			cout << "Computer Choice: Paper" << endl;
			cout << "Round Winner : [Player1]" << endl;
			system("color 27");
			PlayerWins++;

		}
		else if (PlayerChoice == 3 && ComputerChoice == 3)
		{
			cout << "\nPlayer1 Choice: Scissor" << endl;
			cout << "Computer Choice: Scissor" << endl;
			cout << "Round Winner : [No Winner]" << endl;
			system("color 67");
			DrawTimes++;

		}
		else
		{
			cout << "Try Again... ";
		}

		cout << "______________________________" << endl;

		
		stGameresult.ComputerWins = ComputerWins;
		stGameresult.PlayerWins = PlayerWins;
		stGameresult.DrawTimes = DrawTimes;
		stGameresult.Rounds = rounds;

		if (ComputerWins>PlayerWins)
		{
			stGameresult.FinalWinner = "Computer";
		}
		else if (PlayerWins>ComputerWins) {
			stGameresult.FinalWinner = "Player1";

		}
		else
		{
			stGameresult.FinalWinner = "No Winner";
		}

		

	}

	GameOverScreen(stGameresult);

	char playagain;
	cout << "\t\t\tDo you want to play again? Y/N? ";
	cin >> playagain;

	if (playagain == 'y')
	{
		StartTheGame();
	}
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	StartTheGame();
}