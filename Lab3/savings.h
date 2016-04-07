#ifndef SAVINGS_H_
#define SAVINGS_H_
#include <stdlib.h>
#include "account.h"
using namespace std;

class Savings : public Account
{
private:
	double profit;
public:
	Savings();
	~Savings();
	void PrintInfo();
	void SetProfit(double);
};

#endif