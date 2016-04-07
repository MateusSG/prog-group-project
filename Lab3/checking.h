#ifndef CHECKING_H_
#define CHECKING_H_
#include <stdlib.h>
#include "account.h"
using namespace std;

class Checking : public Account
{
private:
	int checks;
public:
	Checking();
	~Checking();
	void PrintInfo();
	void SetChecks(int);
};

#endif