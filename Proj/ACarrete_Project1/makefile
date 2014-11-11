# ACarrete Make Fild
# -c command line option compiles the source code into and an object file (.o file)
# -I (dash i) option tells the compiler where to find an external header(.h) file
# g++ -I/Library/Frameworks/SDL.framework/Headers main.cpp SDLmain.m -framework SDL -framework Cocoa

LIBS=include/Handler include/AUDFile
INCLUDE_PATH=include/

new: clean \
	cli_exec 
cli_exec: libraries
	g++ cli/main.cpp $(wildcard libraries/*) -I$(INCLUDE_PATH) -o cli_exec

libraries:
	mkdir libraries/
	for dir in $(LIBS); do \
		cd $$dir; \
		g++ -c *.cpp -I../; \
		mv *.o ../../libraries; \
		cd -; \
	done

clean:
	rm -rf libraries/ cli_exec

r: new2 \
	./cli_exec

new2:clean \
	sdl_exec

sdl_exec: libraries
	g++ cli/main.cpp cli/SDLmain.m $(wildcard libraries/*) -I$(INCLUDE_PATH) -I/Library/Frameworks/SDL.framework/Headers -o cli_exec -framework SDL -framework Cocoa