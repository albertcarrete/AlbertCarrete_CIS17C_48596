/*	===========================================================
|:	File: WAVFile.cpp
|:	-----------------------------------------------------------
|:	Developer: Albert Carrete
|:	Class: CSC 17C 
|:	=========================================================*/

#include "WAVFile.h"

WAVFile::WAVFile(){

	headerMap["ChunkID"] = headerData(0,4,0);	// Marks the file as a riff file
	headerMap["ChunkSize"] = headerData(4,4,0);	// Size of the overall file
	headerMap["Format"] = headerData(8,4,0);	// File type headerMap
	headerMap["Subchunk1ID"]= headerData(12,4,0);	// Format chunk marker
	headerMap["Subchunk1Size"]= headerData(16,4,0); 	// Length of format data
	headerMap["AudioFormat"]= headerData(20,2,0);	// Type of format (1 is PCM)
	headerMap["NumChannels"]= headerData(22,2,0);
	headerMap["SampleRate"]= headerData(24,4,0);
	headerMap["ByteRate"]= headerData(28,4,0);
	headerMap["BlockAlign"]= headerData(32,2,0);
	headerMap["BitsPerSample"]= headerData(34,2,0);
	headerMap["Subchunk2ID"]= headerData(36,4,0);
	headerMap["Subchunk2Size"]= headerData(40,4,0);
}	
WAVFile::~WAVFile(){

}
void WAVFile::set_HeaderData(BYTE* hData){
	std::cout << "Sample header data:" << std::endl;
	for(int i = 0; i < get_HeaderLength(); i++){
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)hData[i];
	}
	std::cout << std::endl;

	for(auto outer_iter=headerMap.begin(); outer_iter!=headerMap.end(); ++outer_iter) {
		std::cout << "Editing: " << outer_iter->first << std::endl;
		std:: cout << "ByteSize: " << outer_iter->second.byteSize << std::endl;
		std::cout << "ByteOffset: " << std::dec << outer_iter->second.byteOffset <<std::endl;
		int offset = outer_iter->second.byteOffset;
	    // for(auto inner_iter=outer_iter->second.begin(); inner_iter!=outer_iter->second.end(); ++inner_iter) {
	    //     std::cout << inner_iter->second << std::endl;
	    // }
	    // std::cout << std::hex << std::setw(2) << std::setfill('0') << outer_iter->second.data;
	    outer_iter->second.datum = new BYTE[outer_iter->second.byteSize];
		int z = 0;
	    for(int i = offset; i < offset + outer_iter->second.byteSize; i++){
	    	outer_iter->second.datum[z] = hData[i];
	    	z++;
	    }
	    std::cout << std::endl;
	}
}
void WAVFile::get_ChunkID(){
	std::string strem(reinterpret_cast<char*>(headerMap["ChunkID"].datum));
	std::cout << "ChunkID: ";
	std::cout << strem;
	std::cout << std::endl;
}
void WAVFile::get_ChunkSize(){
	std::cout << "ChunkSize: ";
	unsigned int ChunkSize = 0;
	unsigned int rate = 1;

	for(int i = 0; i < headerMap["ChunkSize"].byteSize;i++){
		ChunkSize += (rate * (int)headerMap["ChunkSize"].datum[i]);
		rate = rate * 256;
	}
	std::cout << std::dec << ChunkSize;
	std::cout << std::endl;	
}
void WAVFile::get_Format(){
	std::string strem(reinterpret_cast<char*>(headerMap["Format"].datum));
	std::cout << "Format: ";
	std::cout << strem;
	std::cout << std::endl;
}
void WAVFile::get_Subchunk1ID(){
	std::string strem(reinterpret_cast<char*>(headerMap["Subchunk1ID"].datum));
	std::cout << "Subchunk1ID: ";
	std::cout << strem;
	std::cout << std::endl;
}
void WAVFile::get_Subchunk1Size(){
	std::cout << "Subchunk1Size: ";
	unsigned int Subchunk1Size = 0;
	unsigned int rate = 1;

	for(int i = 0; i < headerMap["Subchunk1Size"].byteSize;i++){
		Subchunk1Size += (rate * (int)headerMap["Subchunk1Size"].datum[i]);
		rate = rate * 256;
	}
	std::cout << std::dec << Subchunk1Size;
	std::cout << std::endl;		
}
void WAVFile::get_AudioFormat(){
	std::cout << "AudioFormat: ";
	unsigned int AudioFormat = 0;
	unsigned int rate = 1;

	for(int i = 0; i < headerMap["AudioFormat"].byteSize;i++){
		AudioFormat += (rate * (int)headerMap["AudioFormat"].datum[i]);
		rate = rate * 256;
	}
	std::cout << std::dec << AudioFormat;
	std::cout << std::endl;		
}
void WAVFile::get_NumChannels(){
	std::cout << "NumChannels: ";
	unsigned int NumChannels = 0;
	unsigned int rate = 1;

	for(int i = 0; i < headerMap["NumChannels"].byteSize;i++){
		NumChannels += (rate * (int)headerMap["NumChannels"].datum[i]);
		rate = rate * 256;
	}
	std::cout << std::dec << NumChannels;
	std::cout << std::endl;		
}
void WAVFile::get_SampleRate(){
	std::cout << "SampleRate: ";
	std::cout << std::dec << endianconversion("SampleRate");
	std::cout << std::endl;		
}
void WAVFile::get_ByteRate(){
	std::cout << "ByteRate: ";
	std::cout << std::dec << endianconversion("ByteRate");
	std::cout << std::endl;		
}
void WAVFile::get_BlockAlign(){
	std::cout << "BlockAlign: ";
	std::cout << std::dec << endianconversion("BlockAlign");
	std::cout << std::endl;		
}
void WAVFile::get_BitsPerSample(){
	std::cout << "BitsPerSample: ";
	std::cout << std::dec << endianconversion("BitsPerSample");
	std::cout << std::endl;		
}
void WAVFile::get_Subchunk2ID(){
	std::string strem(reinterpret_cast<char*>(headerMap["Subchunk2ID"].datum));
	std::cout << "Subchunk1ID: ";
	std::cout << strem;
	std::cout << std::endl;
}
void WAVFile::get_Subchunk2Size(){
	std::cout << "Subchunk2Size: ";
	std::cout << std::dec << endianconversion("Subchunk2Size");
	std::cout << std::endl;		
}
void WAVFile::get_HeaderData(){
	get_ChunkID();
	get_ChunkSize();
	get_Format();
	get_Subchunk1ID();
	get_Subchunk1Size();
	get_AudioFormat();
	get_NumChannels();
	get_SampleRate();
	get_ByteRate();
	get_BlockAlign();
	get_BitsPerSample();
	get_Subchunk2ID();
	get_Subchunk2Size();
	readDataChunk();
}
unsigned int WAVFile::endianconversion(std::string mapname){
	unsigned int value = 0;
	unsigned int rate = 1;

	for(int i = 0; i < headerMap[mapname].byteSize;i++){
		value += (rate * (int)headerMap[mapname].datum[i]);
		rate = rate * 256;
	}
	return value;
}
void WAVFile::readDataChunk(){
	std::cout << "Testing Data Chunk: " << std::endl;
	std:: cout << "OFF" << "    " <<  "HEX" << "    " << "Int" << "    " << "Int16" << std::endl;
	// std::string twobyte = "";
	std::stringstream twobyte;
	std::string str;
	int num;
	int16_t num16;

	/*HOW MUCH DATA*/
	for(int i = get_HeaderLength(); i < 500; i+=2){
		std::cout << std::setw(4) << std::setfill('0')<< i << "   ";
		twobyte << std::hex << std::setw(2) << std::setfill('0') << (int)fileBuffer[i+1] << std::setw(2) << std::setfill('0') << (int)fileBuffer[i];
		str = twobyte.str();
		std::cout << twobyte.str() << "   ";
		twobyte >> num;
		std::cout << std::setw(5)<< std::setfill(' ') << num <<"    ";
		num16 = num;
		std::cout << num16 << std::endl;	
		wavint16.push_back(num);
		num = 0;
		twobyte.str(""); 
		twobyte.clear();
	}
}
std::vector<int16_t> WAVFile::get_DataChunk(){
	// vec.swap(wavint16);
	return wavint16;
}