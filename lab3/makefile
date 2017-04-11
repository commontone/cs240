all: lab3

lab3: lab3.o AntHill.o Ant.o
	g++ -g lab3.o Ant.o AntHill.o -lm -o lab3

lab3.o: lab3.cpp AntHill.h Ant.h
	g++ -g -c lab3.cpp -o lab3.o

AntHill.o: AntHill.cpp AntHill.h
	g++ -g -c AntHill.cpp -o AntHill.o

Ant.o: Ant.cpp Ant.h
	g++ -g -c Ant.cpp -o Ant.o

run: lab3
	./lab3

checkmem: lab3
	valgrind ./lab3

clean:
	rm *.o lab3
