#ifndef WAVFILE_H
#define WAVFILE_H

#include "AUDFile.h"

class WAVFile : public AUDFile{

protected:
	unsigned int endianconversion(std::string);
	void virtual readDataChunk();
public:
	WAVFile();
	~WAVFile();
  	virtual void set_HeaderData(BYTE*);
	virtual int get_HeaderLength(){ return 44;};
	virtual std::string get_Extension(){return ".wav";};
	virtual void get_HeaderData();

	struct WavHeader{
		std::string ChunkID;
		unsigned int ChunkSize;
		std::string Format;
		std::string SubChunk1ID;
		unsigned int SubChunk1Size;
		unsigned int AudioFormat;
		unsigned int NumChannels;
		unsigned int SampleRate;
		unsigned int ByteRate;
		unsigned int BlockAlign;
		unsigned int BitsPerSample;
		std::string Subchunk2ID;
		unsigned int Subchunk2Size;
	};
	void get_ChunkID();
	void get_ChunkSize();
	void get_Format();
	void get_Subchunk1ID();
	void get_Subchunk1Size();
	void get_AudioFormat();
	void get_NumChannels();
	void get_SampleRate();
	void get_ByteRate();
	void get_BlockAlign();
	void get_BitsPerSample();
	void get_Subchunk2ID();
	void get_Subchunk2Size();


	virtual std::vector<int16_t> get_DataChunk();
};
#endif