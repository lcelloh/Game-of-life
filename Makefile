all: compile run

compile:
	g++ -std=c++17 -o Application src/Application.cpp -I/src

run:
	./Application

rem:
	rm Application 
