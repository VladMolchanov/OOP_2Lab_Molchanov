#include <iostream>
#include <Windows.h>
#include <new.h>
#include <string>
#include <fstream>
#include "Man.h"
#include "AllExceptionsFile.h"
#include "InputValidation.h"
#pragma warning (disable:4703)
using namespace std;

Man *objMan = new Man [25];
int objManCounter = 0;
inputValidation bufObjInpValid;
char* constExOpenFileM = "Error!Can't open the file.";
char* constExCloseFileM = "Error!Can't close the file.";
char* constExErrorRecordM = "Error writing to file.";

int numberInputStream (){
	int bufNumber;
	int stateOfStream;
	while(1){
		cin >> bufNumber;
		stateOfStream = cin.rdstate();
		if(!stateOfStream){
			cin.ignore(100 , '\n');
			break;
			}
		cin.clear();
		cout << "Incorrect entry, please try again :";
		cin.ignore(100 , '\n');
		}
	return bufNumber;
	}

int mainMenu() {
	int bufChoise;
	cout << "Enter :"<< endl << "[1] Create a new record;" << endl;
	cout << "[2] View all records;" << endl;
	cout << "[3] Write data to file;" << endl;
	cout << "[4] Complete the implementation." <<endl;
	bufChoise = bufObjInpValid.inputNumber();
	return bufChoise;
	}

int createNewRecordMenu() {
	int bufChoise;
	cout << "Enter :"<< endl << "[1] Input using special methods;" << endl;
	cout << "[2] Input using overloaded operators;" << endl;
	cout << "[3] Return to the main menu." << endl;
	bufChoise = bufObjInpValid.inputNumber();
	return bufChoise;
	} 

void createNewRecord(){
	int cycleVariable=1;
	do{
		switch (createNewRecordMenu()){
		case 1:{
			string name;
			string surname;
			int age = 0;
			cout << "New record:" << endl << "Enter name:";
			name = bufObjInpValid.inputWord();
			cout << "Enter surname:";
			surname = bufObjInpValid.inputWord();
			cout << "Enter age:";
			age = numberInputStream();
			objMan[objManCounter].set(name , surname , age);
			objManCounter++;
			cycleVariable = 0;
			break;
			}
		case 2:{
			cin >> objMan[objManCounter];
			objManCounter++;
			cycleVariable = 0;
			break;
			}
		case 3:{
			cycleVariable = 0;
			break;
			}
		default:{
			cout << "Try it again." <<endl;
			}
		}
		}while(cycleVariable);
	}

void outData() { 
	cout <<"    Surname    "<<"     Name     "<<"      Age      "<<endl;
	for(int buf=0;buf<objManCounter;buf++){
		cout << objMan[buf];
			}
	}

void recordData() {
	cout << objManCounter;
	try{
		fstream dataFileDelete("DataFile.txt",ios_base::trunc|ios::out);
		if(!dataFileDelete.is_open()){
			throw exOpenFile (constExOpenFileM);
			}
		dataFileDelete.close ();
		if(dataFileDelete.is_open()){
			throw exCloseFile (constExCloseFileM);
			}
		for(int buf=0;buf<objManCounter;buf++){
			objMan[buf].recordData();
			}
		cout << "Data was successfully recorded." << endl;
		}
	catch(exOpenFile exMessage){
		cout << exMessage.what() << endl;
		}
	catch(exRecordFile exMessage){
		cout << exMessage.what() << endl;
		}
	catch(exCloseFile exMessage){
		cout << exMessage.what() << endl;
		}
	}

void readingData() {
	try{
			char *bufName;
			char *bufSurname;
			char *bufAge;
			bufName = new char [100];
			bufSurname = new char [100];
			bufAge = new char [100];
			fstream dataFile("DataFile.txt",ios_base::in);
			if(!dataFile.is_open()){
				throw exOpenFile (constExOpenFileM);
				}
			while(!dataFile.eof()){
				dataFile.getline(bufName , 99 , '\n');
				dataFile.getline(bufSurname , 99 , '\n');
				dataFile.getline(bufAge , 99 , '\n');
				objMan[objManCounter].set(bufName , bufSurname , atoi(bufAge));
				if ( atoi(bufAge) != 0){
					objManCounter++;
					}
				}
			dataFile.close ();
			if(dataFile.is_open()){
				throw exCloseFile (constExCloseFileM);
				}
			if(objManCounter > 0){
				cout << "Data was successfully reading." << endl;
				}
		}
	catch(exOpenFile exMessage){
		cout << exMessage.what() << endl;
		}
	catch(exCloseFile exMessage){
		cout << exMessage.what() << endl;
		}
	}

void recordIndicativeFile (Man bufObj) {
	int stateOfStream;
	fstream dataFile("IndicativeDataFile.txt",ios::app);
	if(!dataFile.is_open()){
		throw exOpenFile (constExOpenFileM);
		}
	dataFile << bufObj;
	stateOfStream = dataFile.rdstate();
	if (stateOfStream) {
		if (stateOfStream&ios::badbit) {
			cout << "(badbit)";
			throw exRecordFile (constExErrorRecordM);
			}
		if (stateOfStream&ios::failbit) {
			cout << "(failbit)";
			throw exRecordFile (constExErrorRecordM);
			}
		}
	dataFile.close ();
	if(dataFile.is_open()){
		throw exCloseFile (constExCloseFileM);
		}
	}

void indicativeFile () {
	try{
		fstream dataFileDelete("IndicativeDataFile.txt",ios_base::trunc|ios::out);
		if(!dataFileDelete.is_open()){
			throw exOpenFile (constExOpenFileM);
			}
		dataFileDelete <<"    Surname    "<<"     Name     "<<"      Age      \n";
		dataFileDelete.close ();
		if(dataFileDelete.is_open()){
			throw exCloseFile (constExCloseFileM);
			}
		for(int buf=0;buf<objManCounter;buf++){
			recordIndicativeFile(objMan[buf]);
			}
		cout << "Bye!" << endl;
		}
	catch(exOpenFile exMessage){
		cout << exMessage.what() << endl;
		}
	catch(exRecordFile exMessage){
		cout << exMessage.what() << endl;
		}
	catch(exCloseFile exMessage){
		cout << exMessage.what() << endl;
		}
	}

void main() {
	cin.unsetf(ios::skipws);
	readingData();
	while(1){
		switch (mainMenu()) {
			case 1:{
				createNewRecord();
				break;
				}
			case 2:{
				outData();
			break;
				}
			case 3:{
				recordData ();
				break;
				}
			case 4:{
				indicativeFile ();
				exit(0);
				break;
				}
			default:{
				cout << "Try it again." <<endl;
				}
			}
		}
	}

