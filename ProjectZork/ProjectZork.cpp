// 4/7/2016
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	// Variables
	string userInput = "";
	// Room arrRoom[5];

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