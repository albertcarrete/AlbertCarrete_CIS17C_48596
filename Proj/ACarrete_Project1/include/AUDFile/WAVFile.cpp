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
void WAVFile::get_SGroupID(){

	std::string strem(reinterpret_cast<char*>(headerMap["ChunkID"].datum));
	std::cout << "ChunkID: ";
	// for(int i = 0; i < headerMap["ChunkID"].byteSize;i++){
	// 	std::cout << headerMap["ChunkID"].datum[i];
	// }
	std::cout << strem;
	std::cout << std::endl;
}
void WAVFile::get_dwFileLength(){
	std::cout << "ChunkSize: ";
	for(int i = 0; i < headerMap["ChunkSize"].byteSize;i++){
		std::cout << (int)headerMap["ChunkSize"].datum[i];
	}
	std::cout << std::endl;	
}
void WAVFile::get_FORMAT(){
	std::cout << "Format: ";
	for(int i = 0; i < headerMap["Format"].byteSize;i++){
		std::cout << headerMap["Format"].datum[i];
	}
	std::cout << std::endl;	
}
void WAVFile::get_FCHUNK(){
	std::cout << "SubChunk1ID: ";
	for(int i = 0; i < headerMap["SubChunk1ID"].byteSize;i++){
		std::cout << headerMap["SubChunk1ID"].datum[i];
	}
	std::cout << std::endl;	
}

void WAVFile::get_HeaderData(){
	for(auto outer_iter=headerMap.begin(); outer_iter!=headerMap.end(); ++outer_iter) {
		std::cout << outer_iter->first << ": ";
		for(int i = 0; i < outer_iter->second.byteSize;i++){
			std::cout << (int)outer_iter->second.datum[i];
		}
		std::cout << std::endl;			
	}
	std::cout << "BYTE rate: ";
	unsigned int byterate = 0;
	unsigned int rate = 1;

	for(int i = 0; i < headerMap["ByteRate"].byteSize;i++){
		byterate += (rate * (int)headerMap["ByteRate"].datum[i]);
		rate = rate * 256;
	}
	std::cout << std::dec << byterate;
	std::cout << std::endl;	
	get_SGroupID();
	// get_dwFileLength();
	// get_FORMAT();
	// get_FCHUNK();
}