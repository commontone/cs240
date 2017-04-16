all: program2

program2: program2.o
	g++ -std=c++11 -g program2.o -lm -o program2
	
program2.o: program2.cpp
	g++ -std=c++11 -c program2.cpp -o program2.o
	
run: program2
	./program2

checkmem: program2
	valgrind ./program2

clean:
	rm *.o program2
