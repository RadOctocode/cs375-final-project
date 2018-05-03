FLAGS = -Wall -Wextra -g -std=c++14

all: main.o bestfirst.o bruteforce.o
	g++ $(FLAGS) main.o bestfirst.o bruteforce.o -o main

main.o: main.cpp utility.hpp
	g++ $(FLAGS) main.cpp -c

bestfirst.o: bestfirst.cpp utility.hpp
	g++ $(FLAGS) bestfirst.cpp -c

bruteforce.o: bruteforce.cpp utility.hpp
	g++ $(FLAGS) bruteforce.cpp -c
