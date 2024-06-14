all:
	g++ -c main.cpp
	g++ main.o -o CoolProgram2 -lsfml-graphics -lsfml-window -lsfml-system
	./CoolProgram2
