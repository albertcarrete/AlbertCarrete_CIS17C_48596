#ifndef WAVFILE_H
#define WAVFILE_H

#include "AUDFile.h"

class WAVFile : public AUDFile{

protected:

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
		std::string Subchuk2ID;
		unsigned int Subchunk2Size;
	};
	void get_SGroupID();
	void get_dwFileLength();
	void get_FORMAT();
	void get_FCHUNK();
};
#endif