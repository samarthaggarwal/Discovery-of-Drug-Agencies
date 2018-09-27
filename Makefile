all: main.cpp 
	g++ -o main main.cpp graph.cpp -std=c++11
	./main test1.graph
	minisat test.satinput test.satoutput
	cat test.satoutput

soln:
	g++ -o solution solution.cpp
	./solution test.satoutput test1.graph

clean:
	rm main
