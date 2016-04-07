#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <stdlib.h>
#include <string>

using namespace std;

class Account
{
protected:
	string lastName;
	string firstName;
	double balance;
	int accountNo;
	char type;

public:
	void SetName(string, string);
	string ReturnFirstName();
	string ReturnLastName();
	void SetBalance(double);
	double ReturnBalance();
	void SetAccNumber(int);
	void SetType(char);
	char ReturnType();
	virtual void PrintInfo();
	virtual void SetProfit(double);
	virtual void SetChecks(int);

	friend ostream& operator<< (ostream& out, const Account& acc);


	Account();
	~Account();
	

};

#endif