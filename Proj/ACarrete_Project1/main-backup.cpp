//http://www.youtube.com/user/thecplusplusguy
//Thanks for the typed in code to Tapit85
#include <SDL/SDL.h>

void putPixel(SDL_Surface* dest,int x,int y, int r, int g, int b){
	if(x>=0 && x<dest->w && y>=0 && y < dest->h)
		((Uint32*)dest->pixels)[y*dest->pitch/4+x] = SDL_MapRGB(dest->format,r,g,b);
} 
void swapValue(int&a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
void drawLine(SDL_Surface*dest, int x0, int y0, int x1, int y1){
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


int main(int argc, char** argv)
{
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface *screen;
        screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
//      screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_FULLSCREEN);
        bool running = true;
        const int FPS = 30;
        Uint32 start;
        SDL_Event event;
        int mx = 10,my = 10;
        while(running) {
                start = SDL_GetTicks();
                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = false;
                                        break;
                                case SDL_MOUSEMOTION:
                                	mx = event.motion.x;
                                	my = event.motion.y;
                                	break;
                        }
                }
                //logic && render
                SDL_FillRect(screen,NULL,0);
                drawLine(screen,mx,my,320,240);
                SDL_Flip(screen);
 
                if(1000/FPS > SDL_GetTicks()-start) {
                        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                }
        }
        SDL_Quit();
        return 0;
}