all: program3

maptest: Map.o City.o
	g++ -g -std=c++11 Map.o City.o -o maptest.out

program3: Map.o program3.o City.o
	g++ -g -std=c++11 Map.o City.o program3.o -o program3
	
program3.o: program3.cpp
	g++ -g -std=c++11 -c program3.cpp -o program3.o
	
Map.o: Map.cpp Map.h City.h
	g++ -g -std=c++11 -c Map.cpp -o Map.o
	
City.o: City.cpp Map.h City.h
	g++ -g -std=c++11 -c City.cpp -o City.o
	
run: program3
	./program3

checkmem: program3
	valgrind ./program3

clean:
	rm *.o program3 

git: Map.h Map.cpp City.cpp City.h
	git add Map.h Map.cpp City.cpp City.h makefile