#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Man.h"
#include "AllExceptionsFile.h"
#include "InputValidation.h"
#pragma warning (disable:4996)
using namespace std;

char* constExOpenFile = "Error!Can't open the file.";
char* constExCloseFile = "Error!Can't close the file.";
char* constExErrorRecord = "Error writing to file.";

Man :: Man (){
	name = "";
	surname = "";
	age = 0;
	}

Man :: Man (string bufName , string bufSurname , int bufAge ){
	name = bufName;
	surname = bufSurname;
	age = bufAge;
	}

Man :: Man (Man &bufObj) {
	name = bufObj.name;
	surname = bufObj.surname;
	age = bufObj.age;
	}

Man :: ~Man () {
	name = "";
	surname = "";
	age = NULL;
	}

void  Man :: set (string bufName , string bufSurname , int bufAge){
	name = bufName;
	surname = bufSurname;
	age = bufAge;
	}

void Man :: getName () {
	cout << name;
	}

void Man :: getSurname () {
	cout << surname;
	}

void Man :: getAge () {
	cout << age;
	}

void Man :: getAllData () {
	cout << "Name:" << name << endl << "Surname:" << surname << endl << "Age:" << age << endl ;
	}

void Man :: recordData () {
	int stateOfStream;
	fstream dataFile("DataFile.txt",ios::app);
	if(!dataFile.is_open()){
		throw exOpenFile (constExOpenFile);
		}
	dataFile << name << "\n" << surname << "\n" << age << "\n";
	stateOfStream = dataFile.rdstate();
	if (stateOfStream) {
		if (stateOfStream&ios::badbit) {
			cout << "badbit" << endl;
			throw exRecordFile (constExErrorRecord);
			}
		if (stateOfStream&ios::failbit) {
			cout << "failbit" << endl;
			throw exRecordFile (constExErrorRecord);
			}
		}
	dataFile.close ();
	if(dataFile.is_open()){
		throw exCloseFile (constExCloseFile);
		}
	}

ostream &operator<<(ostream &stream, Man obj){
	stream<<" __________________________________________"<<endl;
	stream<<"|"<<setw(15)<<obj.surname;
	stream<<"|"<<setw(15)<<obj.name;
	stream<<"|"<<setw(10)<<obj.age<<"|"<<endl;
	stream<<"|__________________________________________|"<<endl;
	return stream;
	}

istream &operator>>(istream &streamIn, Man &obj){
	int stream = 1;
	while(stream){
		cout << "Enter name:";
		streamIn >> obj.name;
		stream = streamIn.rdstate();
		streamIn.clear();
		streamIn.ignore(100 , '\n');
		}
	stream = 1;
	while(stream){
		cout << "Enter surname:";
		streamIn >> obj.surname;
		stream = streamIn.rdstate();
		streamIn.clear();
		streamIn.ignore(100 , '\n');
		}
	stream = 1;
	while(stream){
		cout << "Enter age:";
		streamIn >> obj.age;;
		stream = streamIn.rdstate();
		streamIn.clear();
		streamIn.ignore(100 , '\n');
		}
	return streamIn;
	}






