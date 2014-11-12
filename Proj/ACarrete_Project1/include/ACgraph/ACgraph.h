/*
|: 	File: AUDHandler.h
|:	Developer: Albert Carrete
|:	Date: November 9, 2014
|:  @package WAV Spek
|:
*/
#include "AUDFile/AUDFile.h"
#include "AUDFile/WAVFile.h"
#include "SDL/SDL.h"
#include <iostream>

#ifndef ACGRAPH_H
#define ACGRAPH_H

class ACgraph{

protected:
	typedef unsigned char BYTE;
	void drawLine(SDL_Surface*, int, int, int, int);
	void putPixel(SDL_Surface*,int,int, int, int, int);
	void swapValue(int&, int&);
	std::vector<int>normalizedPoints;
public:

	ACgraph();
	~ACgraph();
	void init(AUDFile*);

	int get_centerX();
	void graphAUD(AUDFile*,SDL_Surface*);
	void drawPoints(SDL_Surface*);
};

#endif 