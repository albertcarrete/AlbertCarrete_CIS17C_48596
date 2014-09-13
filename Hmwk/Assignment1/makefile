# ACarrete Make Fild
# -c command line option compiles the source code into and an object file (.o file)
# -I (dash i) option tells the compiler where to find an external header(.h) file

LIBS=include/triangular
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
