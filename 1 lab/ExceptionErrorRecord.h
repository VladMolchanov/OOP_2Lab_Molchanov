#include <iostream>
#include "ExceptionCloseFile.h"
using namespace std;

class exRecordFile: public exCloseFile {
public: 
	exRecordFile (char* typeOfException) : exCloseFile (typeOfException) {}
	};
