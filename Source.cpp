#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int numOfbets = 0;
	int numOfsimulations = 0;
	double odds = 50.0;
	double startMoney = 0;
	double money = 0;
	double newMoney = 0;
	double startBet = 0;
	double bet = startBet;
	bool win = false;
	int number = 0;
	int adjOdds = 0;
	int numWins = 0;
	int numLoss = 0;
	int posReturn = 0;
	int negReturn = 0;
	int exit = 0;
	int i = 1;
	int j = 1;

	while (exit != 1)
	{
		cout << "Number of Simulations: ";
		cin >> numOfsimulations;
		cout << "Number of bets: ";
		cin >> numOfbets;
		cout << "Percent change to win (up to three decimal places): ";
		cin >> odds;
		cout << "Starting cash: ";
		cin >> startMoney;
		cout << "Starting bet: ";
		cin >> startBet;


		while (j <= numOfsimulations)
		{
			money = startMoney;
			bet = startBet;


			while ((money >= bet) && (i <= numOfbets))
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
					//cout << "win  ";
				}
				else
				{
					win = false;
					numLoss = numLoss + 1;
					newMoney = money - bet;
					bet = bet * 2;
					//cout << "lose ";
				}

				money = newMoney;
				i = i + 1;
				//cout << money << endl;

			}

			if (money < bet)
			{
				//cout << "Not enough money to continue betting.\n";

			}
			else
			{
				//cout << "Congratulations!\n";
			}
			
			if (money > startMoney)
			{
				posReturn = posReturn + 1;
			}
			else
			{
				negReturn = negReturn + 1;
			}

			
			i = 1;
			j = j + 1;
			
		}

		cout << "Positive Returns: " << posReturn << endl;
		cout << "Negative Returns: " << negReturn << endl;
		j = 1;
		cin >> exit;

	}
}