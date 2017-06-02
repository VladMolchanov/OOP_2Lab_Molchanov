#include <iostream>
using namespace std;

class inputValidation {
	char* inputLine;
	int positionNumber;
	char bufGetch;
public:
	inputValidation ();
	int inputNumber ();
	char* inputWord ();
	~inputValidation (){}
	};