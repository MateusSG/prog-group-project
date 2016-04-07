// 4/7/2016
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//void RoomSetup(Enviroment ptr&, Item i1, Item i2)

// Actions:
// USE, GIVE, ATTACK, GO, PICK, SEARCH, COMBINEg

int main()
{
	// Variables
	string userInput = "";
	// Room game[5];

	Enviroment* roomPtr[5]; // Declaring Rooms

	for (int i = 0; i < 5; i++) // 
	{
		new roomPtr[i];
	}





	// String Tokenizer
	char str[] = "EAT APPLE";
	char * pch;

	cout << "Splitting string " << str << "into tokens :" << endl;

	pch = strtok(str, " ");

	while (pch != NULL)
	{
		cout << pch << endl;
		pch = strtok(NULL, " ");
	}

	// MAIN PROGRAM

	cout << endl << "Welcome to Mr Harvey and The Quest for The Fountain Pen!" << endl;

	cout << "Intro: " << "You are in a dark room. You see a shiny LIGHTER on the floor next to you." << endl;
	cin >> userInput;



	


	return 0;
}


void RoomSetup(Enviroment ptr, Item i1, Item i2)
{
	for (i = 0; i < 5; i++)
	{
		new ptr[i];
		ptr[i]->item1 = i1;
		
	}

	
}


 */