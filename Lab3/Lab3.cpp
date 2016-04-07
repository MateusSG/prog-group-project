// Mateus Santana Gurgel
// 3/25/2016
// BANK ACCUNT - Inspired by Van Damme\
// QUESTIONS - ASK ABOUT DECIMAL PLACES ON DOUBLES
//			 - ASK ABOUT SETTYPE ON ACCOUNT.H

#include <iostream>
#include <stdlib.h>		// system("CLS")
#include <windows.h>	// sleep(milisecconds)
#include "account.h"
#include "savings.h"
#include "checking.h"

using namespace std;

void PrintMainMenu(); // Prints main menu
void PrintEditMenu(); // Prints options for editing account

int main()
{
	char selection = ' ';		// char variable used to store the selection of the user
	bool end = false;			// boolean for main loop
	bool endEdit = false;		// boolean for edit loop
	int numAcc = 0;				// Stores number of accounts created
	int accSelect = 0;			// Stores the number of the account that's being editted


	// Variables used to temporaly store values
	string strBuffer0 = "";
	string strBuffer1 = "";
	int intBuffer = 0;
	char chrBuffer = ' ';
	double douBuffer = 0;
	double tempDou = 0;


	Account* ptrAcc[5];

	while (end == false) // Main program loop
	{
		system("CLS");
		PrintMainMenu();

		cout << endl << "Please make a selection: ";
		cin >> selection;
		selection = toupper(selection);

		switch (selection)
		{
		case 'A': // displays a list  of existing bank accounts
			if (numAcc == 0)
			{
				cout << endl << "No accounts have been created yet. Returning to main menu...";
				Sleep(2000);
			}
			else
			{
				for (int i = 0; i < numAcc; i++)  // One run per account
				{
					ptrAcc[i]->PrintInfo();
				}

				cout << endl << "Press ENTER to return to main menu...";
				cin.ignore();
				cin.get();

			}
			break;

		case 'B': // displays “Cannot add more than 5 accounts,” when 5  accounts already exist.  Otherwise,  the  program  prompts  the  user  to select  between  adding  a  checking  account  or  a savings account.

			if (numAcc == 5) // Too many accounts
			{
				cout << endl << "Cannot add more than 5 accounts" << endl
					<< "Returning to main menu..." << endl;
				Sleep(2000);
			}
			else // Create a NEW account
			{
				cout << "Create a SAVINGS or a CHECKING account?(S/C) ";
				cin >> selection;
				selection = toupper(selection);

				if (selection == 'S') // Creates SAVINGS acc
				{
					ptrAcc[numAcc] = new Savings(); // Memory allocation					

					// Set type
					ptrAcc[numAcc]->SetType('S');

					// Get name
					cout << endl << "Please input the FIRST NAME of the Savings account owner: ";
					cin >> strBuffer0;

					cout << endl << "Please input the LAST NAME of the Savings account owner: ";
					cin >> strBuffer1;

					ptrAcc[numAcc]->SetName(strBuffer0, strBuffer1); // Sets the name inside the object

					// Get balance
					cout << endl << "Please input the BALANCE of the Savings account : ";
					cin >> douBuffer;

					ptrAcc[numAcc]->SetBalance(douBuffer); // Sets the balance inside the object

					// Set account number
					ptrAcc[numAcc]->SetAccNumber(numAcc + 1); // Uses the number of current accounts plus one to set the number of the account

					cout << "Your Savings account has been created. Account No: " << numAcc + 1 << endl;

					numAcc++; // Increments the total number of accounts

					cout << "Returning to main menu..." << endl;
					Sleep(2000);

				}
				else if (selection == 'C') // Creates Checkings acc
				{
					ptrAcc[numAcc] = new Checking();

					// Set type
					ptrAcc[numAcc]->SetType('C');

					// Get name
					cout << endl << "Please input the FIRST NAME of the Checking account owner: ";
					cin >> strBuffer0;

					cout << endl << "Please input the LAST NAME of the Checking account owner: ";
					cin >> strBuffer1;

					ptrAcc[numAcc]->SetName(strBuffer0, strBuffer1); // Sets the name inside the object

					// Get balance
					cout << endl << "Please input the BALANCE of the Checking account : ";
					cin >> douBuffer;

					ptrAcc[numAcc]->SetBalance(douBuffer); // Sets the balance inside the object

					// Set account number
					ptrAcc[numAcc]->SetAccNumber(numAcc + 1); // Uses the number of current accounts plus one to set the number of the account

					cout << endl << "Your Savings account has been created. Account No: " << numAcc + 1 << endl;
					numAcc++;

					cout << "Returning to main menu..." << endl;
					Sleep(2000);
				}
				else // Invalid selection
				{
					cout << "Invalid selection. Returning to main menu" << endl;
					Sleep(2000);
					break;
				}
			}
			break;

		case 'C': // let the user search for an account by account number
		
			endEdit = false;
			if (numAcc == 0) // Check if at least one account has been created
			{
				endEdit = true;
				cout << endl << "No accounts have been created yet. Returning to main menu...";
				Sleep(2000);
			}
			else // There is at least one account
			{
				cout << endl << "Please input the NUMBER of the account you would like to edit: ";
				cin >> accSelect;
				

				if (accSelect > numAcc) // Check if desired account exists
				{
					cout << "The account of No " << accSelect << " does not exist. Returning to main menu...";
					Sleep(2000);
				}
				else // Account exists. START EDITING
				{
					accSelect--;
					while (endEdit == false)
					{
						
						ptrAcc[accSelect]->PrintInfo();
						PrintEditMenu();

						chrBuffer = ptrAcc[accSelect]->ReturnType();

						if (chrBuffer == 'S')	// Savings Account
							cout << "e.Add PROFIT" << endl;
						else										// Checking Account
							cout << "e.Add CHECKS" << endl;

						cout << "f.Return to main menu" << endl;

						cout << endl << "Please make a selection: ";
						cin >> selection;
						selection = toupper(selection);


						switch (selection)
						{
						case 'A': // Edit first name
							cout << endl << "Please input the new FIRST NAME of the account owner: ";
							cin >> strBuffer0; // Gets new first name

							strBuffer1 = ptrAcc[accSelect]->ReturnLastName(); // Saves last name on strBuffer1

							ptrAcc[accSelect]->SetName(strBuffer0, strBuffer1); // Sets full name on the object, now with new first name

							break;
						case 'B': // Edit last name
							cout << endl << "Please input the LAST NAME of the Checking account owner: ";
							cin >> strBuffer1; // Gets new last name

							strBuffer0 = ptrAcc[accSelect]->ReturnFirstName(); // Saves first name on strBuffer0

							ptrAcc[accSelect]->SetName(strBuffer0, strBuffer1); // Sets full name on the object, now with new last name

							break;
						case 'C': // Deposit
							cout << endl << "Please input the amount you want to DEPOSIT: ";
							cin >> douBuffer; // Stores the amount of the deposit on douBuffer

							tempDou = ptrAcc[accSelect]->ReturnBalance(); // Stores current balance on tempDou

							ptrAcc[accSelect]->SetBalance(tempDou + douBuffer); // Sets new balance to current balance + deposit

							break;
						case 'D': // Withdraw
							cout << endl << "Please input the amount you want to WITHDRAW: ";
							cin >> douBuffer; // Stores the amount of the withdraw on douBuffer

							tempDou = ptrAcc[accSelect]->ReturnBalance(); // Stores current balance on tempDou

							if (douBuffer < tempDou) // If withdraw is less than current balance:
								ptrAcc[accSelect]->SetBalance(tempDou - douBuffer); // Sets new balance to current balance - withdraw
							else
							{
								cout << "Operation cannot be completed. Withdraw is larger than current balance. Returning to edit menu..." << endl;
								Sleep(3000);
							}
							break;
						case 'E': // Add profit OR Add checks
							chrBuffer = ptrAcc[accSelect]->ReturnType();
							if (chrBuffer == 'S') // Add profit
							{
								cout << endl << "Please input the amount of PROFIT to be added: ";
								cin >> douBuffer;

								ptrAcc[accSelect]->SetProfit(douBuffer);
							}
							else // Add checks
							{
								cout << endl << "Please input the amount of CHECKS to be added: ";
								cin >> intBuffer;

								ptrAcc[accSelect]->SetChecks(intBuffer);
							}
							break;
						case 'F': // Return to main menu
							endEdit = true;
							cout << endl << "Returning to main menu..." << endl;
							Sleep(2000);
							break;
						default:
							break;
						}

					}
				}

			}
		break;

		case 'D': // Exits the program

			for (int i = 0; i < numAcc; i++) // Return memory back to OS by deleting accounts
			{
				delete ptrAcc[i];
			}

			end = true;

			break;

		default:
			break;
		}
		// End of main program loop

		
	}
	return 0;
}

void PrintMainMenu()
{
	cout <<
		"a.Display a list of existing bank accounts" << endl <<
		"b.Add a new bank account" << endl <<
		"c.Edit an existing bank account" << endl <<
		"d.Exit the program" << endl;
}
void PrintEditMenu()
{
	cout << endl <<
		"a.Edit FIRST name" << endl <<
		"b.Edit LAST name" << endl <<
		"c.Make a DEPOSIT" << endl <<
		"d.Make a WITHDRAW" << endl;
}