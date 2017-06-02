#include <iostream>
#include <conio.h>
#include "InputValidation.h"
using namespace std;

inputValidation :: inputValidation () {
	inputLine = new char [100];
	positionNumber = 0;
	bufGetch = 0;
	}

int inputValidation :: inputNumber () {
	positionNumber = 0;
	while ((bufGetch = _getch())!=13){
		if (bufGetch > 47 && bufGetch <58){
			cout << bufGetch;
			inputLine[positionNumber] = bufGetch; 
			positionNumber++;
			}
		if (bufGetch == 8){
			cout<< "\b \b";
			positionNumber--;
			inputLine[positionNumber] = NULL;
			}
		}
	
	inputLine[positionNumber] = '\0';
	cout << endl;
	return atoi(inputLine);
	}

char* inputValidation :: inputWord () {
	positionNumber = 0;
	while ((bufGetch = _getch())!=13 || positionNumber >= 99){
		if (bufGetch >= 65 && bufGetch <= 90 || bufGetch >= 97 && bufGetch <= 122){
			cout << bufGetch;
			inputLine[positionNumber] = bufGetch; 
			positionNumber++;
			}
		if (bufGetch == 8){
			cout<< "\b \b";
			positionNumber--;
			inputLine[positionNumber] = NULL;
			}
		}
	inputLine[positionNumber] = '\0';
	cout << endl;
	return inputLine;
	}