#ifndef AUDFILE_H
#define AUDFILE_H

#include <string>
#include <iomanip>
#include <iostream>
#include <map>

class AUDFile{

protected:
	typedef unsigned char BYTE;
	BYTE *fileBuffer;
	std::string filepath;
	long filesize;
	long headerlength;
	std::string extension;
	std::map<std::string,int>header;

	struct headerData{
		headerData() : byteOffset(0),byteSize(0),data(0){}
		headerData(int _byteOffset,int _byteSize, int _data):
		byteOffset(_byteOffset),byteSize(_byteSize),data(_data){}

		int byteOffset;
		int byteSize;
		int data;
		BYTE *datum;		
	};
	std::map<std::string,headerData> headerMap;

public:
	AUDFile();
	~AUDFile();
	void set_FilePath(std::string fp);
	std::string get_FilePath();
  	void set_FileData(BYTE *a);
  	BYTE * get_FileData();
  	void set_FileSize(long a);
  	long get_FileSize();
  	virtual void set_HeaderData(BYTE*) = 0;
  	virtual void get_HeaderData() = 0;
  	virtual int get_HeaderLength() = 0; // a pure virtual function
  	virtual std::string get_Extension() = 0;
};

#endif 