#include <iostream>
#include "account.h"
#include <stdlib.h>


// When a ACCOUNT object is CREATED, this function is called
Account::Account() : lastName(""), firstName(""), balance(0), accountNo(0), type(' ')
{


}

// When a ACCOUNT object is CREATED, this function is called
Account::~Account() 
{

}

void Account::SetName(string first, string last)
{
	firstName = first;
	lastName = last;
}
string Account::ReturnFirstName()
{
	return firstName;
}
string Account::ReturnLastName()
{
	return lastName;
}

void Account::SetBalance(double bal)
{
	balance = bal;
}
double Account::ReturnBalance()
{
	return balance;
}

void Account::SetAccNumber(int No)
{
	accountNo = No;
}

void Account::SetType(char ty)
{
	type = ty;
}

char Account::ReturnType()
{
	return type;
}

/*
void Account::PrintInfo()
{
	cout << endl << "Account No: " << accountNo << endl
		 << "Type: " << type << endl
		 << "Owner: " << lastName << ", " << firstName << endl
		 << "Balance: $" << balance << endl;
}
*/

void Account::SetChecks(int ch)
{

}
void Account::SetProfit(double dou)
{
	
}

Account Account::operator+