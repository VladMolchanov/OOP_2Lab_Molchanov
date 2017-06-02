#include <iostream>
#include "ExceptionErrorRecord.h"
using namespace std;

class exOpenFile: public exRecordFile {
public: 
	exOpenFile (char* typeOfException) : exRecordFile (typeOfException) {}
	};

