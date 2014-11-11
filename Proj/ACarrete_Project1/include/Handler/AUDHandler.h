/*
|: 	File: AUDHandler.h
|:	Developer: Albert Carrete
|:	Date: November 9, 2014
|:  @package WAV Spek
|:
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "AUDFile/AUDFile.h"
#include "AUDFile/WAVfile.h"

class AUDHandler{

private:
	//Polymorphic base class
	AUDFile * file1;

	bool MainMenu();
	std::string targetFilePath;
	std::string consolemessage;
	void setTargetFile();

public:
	AUDHandler();
	~AUDHandler();
	void init();


};
// void clear(){
// 	system("clear");
// }