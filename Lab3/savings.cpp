#include <iostream>
#include "savings.h"
using namespace std;


Savings::Savings() : profit(0)
{

}

Savings::~Savings()
{

}
void Savings::PrintInfo()
{
	Account::PrintInfo();
	cout << "Profit: " << profit << endl;
}
void Savings::SetProfit(double dou)
{
	profit = dou;
}