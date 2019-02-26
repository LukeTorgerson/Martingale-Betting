#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int numOfSimulations = 0;
	double odds = 50.0;
	double money = 0;
	double newMoney = 0;
	double startBet = 0;
	double bet = startBet;
	bool win = false;
	int number = 0;
	int adjOdds = 0;
	int numWins = 0;
	int numLoss = 0;
	int exit = 0;
	int i = 1;

	while (exit != 1)
	{
		cout << "Number of simulations: ";
		cin >> numOfSimulations;
		cout << "Percent change to win (up to three decimal places): ";
		cin >> odds;
		cout << "Starting cash: ";
		cin >> money;
		cout << "Starting bet: ";
		cin >> startBet;

		bet = startBet;

		while ((money >= bet) && (i <= numOfSimulations))
		{
			number = ((rand() * rand()) % 10000);
			adjOdds = odds * 100;

			//cout << number << endl;
			//cout << adjOdds << endl;

			if (number < adjOdds)
			{
				win = true;
				numWins = numWins + 1;
				newMoney = money + (bet * .95);
				bet = startBet;
				cout << "win ";
			}
			else
			{
				win = false;
				numLoss = numLoss + 1;
				newMoney = money - bet;
				bet = bet * 2;
				cout << "lose ";
			}

			money = newMoney;
			i = i + 1;
			cout << money << endl;
			
		}

		if (money < bet)
		{
			cout << "Not enough money to continue betting.\n";
			
		}
		else
		{
			cout << "Congratulations!\n";
		}

		cout << "Number of wins: " << numWins << endl << "number of losses: " << numLoss << endl << "Ending Balance: " << money << endl;
		money = 0;
		newMoney = 0;
		numOfSimulations = 0;
		odds = 0;
		startBet = 0;
		numLoss = 0;
		numWins = 0;
		i = 1;
		cin >> exit;

	}


}