#include <iostream>
#include "checking.h"
using namespace std;


Checking::Checking() : checks(0)
{

}
Checking::~Checking()
{

}
void Checking::PrintInfo()
{
	Account::PrintInfo();
	cout << "Checks: " << checks << endl;
}
void Checking::SetChecks(int ch)
{
	checks = ch;
}