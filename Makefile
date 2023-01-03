all: compile run

compile:
	g++ -std=c++17 -o bin/Application src/Application.cpp 

run:
	./bin/Application

clean:
	rm bin/Application 
