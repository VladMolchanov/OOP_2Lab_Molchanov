#include <iostream>
using namespace std;

class exCloseFile: public exception {
public: 
	exCloseFile (char* typeOfException) : exception (typeOfException) {}
	};

