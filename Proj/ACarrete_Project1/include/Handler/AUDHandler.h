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
#include "ACgraph/ACgraph.h"

class AUDHandler{

private:
	//Polymorphic base class
	AUDFile * file1;
	bool MainMenu();
	std::string targetFilePath;
	std::string consolemessage;
	void setTargetFile();
	void GraphTargetData();

public:
	AUDHandler();
	~AUDHandler();
	void init();


};
// void clear(){
// 	system("clear");
// }