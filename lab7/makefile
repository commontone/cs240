all: lab7

lab7: lab7.o BSTree.o
	g++ -std=c++11 -g lab7.o BSTree.o -lm -o lab7
	
lab7.o: lab7.cpp BSTree.h
	g++ -std=c++11 -c lab7.cpp -o lab7.o
	
BSTree.o: BSTree.cpp BSTree.h
	g++ -std=c++11 -c BSTree.cpp -o BSTree.o
	
run: lab7
	./lab7

checkmem: lab7
	valgrind ./lab7

clean:
	rm *.o lab7
