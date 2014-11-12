#include "AUDHandler.h"

AUDHandler::AUDHandler(){
	targetFilePath = "[no file selected]";
}
AUDHandler::~AUDHandler(){

}
void AUDHandler::init(){
	// clear();
	bool x = true;
	do{
		x= false;
		x = MainMenu();
	}while(x);
}
bool AUDHandler::MainMenu(){
	char choice = '0';
	bool mainExit = true, menuExit = true;
	
	do{
		std::cout 
		<< "---------------------------------" 		<< std::endl
		<< "test" 				<< std::endl
		<< "1) Target File > " 	<< targetFilePath 	<< std::endl
		<< "2) Analyze File" 	<< std::endl
		<< "3) Exit"			<< std::endl;
		if(consolemessage != ""){
			std::cout << "! " << consolemessage << std::endl
			<< "- - - - - - - - - - - - - - - -" << std::endl;
		}
		std::cin >> choice;

		if(choice == '1'){
			bool valid = true;
				setTargetFile();
		}
		if(choice == '2'){
			GraphTargetData();
		}
		if(choice == '3'){
			menuExit = false;
		}

	}while(menuExit);
	
	return false;
}
void AUDHandler::setTargetFile(){
	file1 = new WAVFile();

	std::string tempFilePath;
	std::cout << "Enter path to target file." << std::endl << "> ";
	std::cin >> tempFilePath;

	std::ifstream infile(tempFilePath, std::ifstream::binary);
	if(infile.is_open()){
		std::cout << "File opened successfully" << std::endl;
		file1->set_FilePath(tempFilePath);
		tempFilePath = targetFilePath;

		infile.seekg(0, infile.end);
		long length = infile.tellg();
		file1->set_FileSize(length);
		infile.seekg(0,infile.beg);

		unsigned char * buffer = new unsigned char [length];

		std::cout << "Reading " << length << " characters " << std::endl;
			infile.read(reinterpret_cast<char*>(buffer),length);

		if(infile){
			std::cout << "Read "<< length << "/" << infile.gcount() << "characters read successfully" << std::endl;
		}
		else{
			std::cout << "error: only " << infile.gcount() << " could be read";
		}
		std::cout << "Target file is " << file1->get_FileSize() << " bytes long" << std::endl;;

		infile.close();
		file1->set_FileData(buffer);
		file1->get_HeaderData();
	}else{
		consolemessage += "Invalid target file path.";
	}
}
void AUDHandler::GraphTargetData(){
	ACgraph graph;
	graph.init(file1);
}