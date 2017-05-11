all: maptest

maptest: Map.o City.o
	g++ -std=c++11 Map.o City.o -o maptest.out

program3: Map.o program3.o City.o
	g++ -std=c++11 Map.o City.o program3.o -o program3
	
program3.o: program3.cpp
	g++ -std=c++11 -c program3.cpp -o program3.o
	
Map.o: Map.cpp Map.h City.h
	g++ -std=c++11 -c Map.cpp -o Map.o
	
City.o: City.cpp Map.h City.h
	g++ -std=c++11 -c City.cpp -o City.o
	
run: maptest
	./maptest.out

checkmem: maptest
	valgrind ./maptest.out

clean:
	rm *.o maptest.out
