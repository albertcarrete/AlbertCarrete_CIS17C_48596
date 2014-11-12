#include "ACgraph.h"


ACgraph::ACgraph(){

}
ACgraph::~ACgraph(){

}
void ACgraph::init(AUDFile* file){
	    SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface *screen;
        screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
//      screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_FULLSCREEN);
        bool running = true;
        const int FPS = 30;
        Uint32 start;
        SDL_Event event;
        int mx = 10,my = 10;
		graphAUD(file,screen);

        while(running) {
                start = SDL_GetTicks();
                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = false;
                                        break;
                                // case SDL_MOUSEMOTION:
                                // 	mx = event.motion.x;
                                // 	my = event.motion.y;
                                // 	break;
                        }
                }
                //logic && render
                SDL_FillRect(screen,NULL,0);
                drawLine(screen,0,0,640,480);
                drawLine(screen,480,640,0,0);
                drawLine(screen,0,get_centerX(),640,get_centerX());
                drawPoints(screen);
                SDL_Flip(screen);
 
                if(1000/FPS > SDL_GetTicks()-start) {
                        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                }
        }
        SDL_Quit();
}
void ACgraph::putPixel(SDL_Surface* dest,int x,int y, int r, int g, int b){
	if(x>=0 && x<dest->w && y>=0 && y < dest->h)
		((Uint32*)dest->pixels)[y*dest->pitch/4+x] = SDL_MapRGB(dest->format,r,g,b);
} 
void ACgraph::swapValue(int&a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
void ACgraph::drawLine(SDL_Surface*dest, int x0, int y0, int x1, int y1){
	bool step = abs(x1 - x0) < abs(y1 - y0);

	if(step){
		swapValue(x0,y0);
		swapValue(x1,y1);
	}
	if(x1<x0){
		swapValue(x0,x1);
		swapValue(y0,y1);
	}
	float error = 0.0;
	float roundError = (float)abs(y1-y0)/(x1-x0); // approximations
	int y = y0;
	int ystep = (y1>y0? 1: -1);
	for(int i = x0; i<x1; i++){
		if(step){
			putPixel(dest,y,i,255,255,255);
		}
		else{
			putPixel(dest,i,y,255,255,255);
		}
		error+=roundError;
		if(error>=0.5){
			y+=ystep;
			error -= 1.0;
		}
	}
}
int ACgraph::get_centerX(){
	return 480/2;
}
void ACgraph::graphAUD(AUDFile *file,SDL_Surface*dest){

	float tempPercent;
	float normalizedLocation;
	int i;
		std::vector<int16_t> new_(file->get_DataChunk());
	for (std::vector<int16_t>::iterator it = new_.begin() ; it != new_.end(); ++it){
		std:: cout << ' ' << *it;
    	tempPercent = (float)*it/32767;
    	normalizedLocation = 480*tempPercent;
    	i = int(normalizedLocation + 0.5);
    	normalizedPoints.push_back(i);
    	std::cout << ' ' << i;
    	std::cout << ' ' << (float)*it/32767;
    	// drawLine(dest,480,0,0,0);
	}
}
void ACgraph::drawPoints(SDL_Surface*dest){
	int init = 0;
	for (std::vector<int>::iterator it = normalizedPoints.begin() ; it != normalizedPoints.end(); ++it){
		drawLine(dest,init,0,init,*it);
		init++;
	}
}