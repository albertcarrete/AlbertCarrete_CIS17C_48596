#include "AUDFile.h"

AUDFile::AUDFile(){
	filepath = "";
}
AUDFile::~AUDFile(){

}
void AUDFile::set_FilePath(std::string fp){
	filepath = fp;
	std::cout << "Filepath set to: " << fp << std::endl;
}
std::string AUDFile::get_FilePath(){
	return filepath;
}
void AUDFile::set_FileData(BYTE *a){
	std::cout << "=============================" << std::endl;
	std::cout << "Creating file buffer of size " << filesize << std::endl;
	fileBuffer = new BYTE[filesize];
	long count = 0;
	for(long i = 0; i < filesize; i++){
		fileBuffer[i] = a[i];
	}
	std::cout << "Complete!" << std::endl;
	std::cout << "Displaying first " << get_HeaderLength() <<" bytes of buffered file:" << std::endl;
	BYTE* headerBuffer = new BYTE[get_HeaderLength()];
	for(int y = 0; y < get_HeaderLength(); y++){
		std::cout << std::hex << std::setw(2) << std::setfill('0') <<(int)fileBuffer[y] << " ";
		headerBuffer[y] = fileBuffer[y];
	}
	set_HeaderData(headerBuffer);

	for(long x = 1; x < 17; x++){
		std::cout << std::hex << std::setw(2) << std::setfill('0') <<(int)fileBuffer[count] << " ";

		if(x % 8 == 0 && x > 4){
			std::cout << std::endl;
		}
		if(x % 4 == 0 && x % 8 != 0){
			std::cout << " ";
		}
		count++;
	}
	std::cout << "=============================" << std::endl;
}
unsigned char * AUDFile::get_FileData(){
	return fileBuffer;
}
void AUDFile::set_FileSize(long a){
	filesize = a;
}
long AUDFile::get_FileSize(){
	return filesize;
}