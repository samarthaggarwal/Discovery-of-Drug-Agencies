all: main.cpp 
	g++ -o main main.cpp graph.cpp -std=c++11
	./main testcases/jumbotest.graph
	./minisat test.satinput test.satoutput
	cat test.satoutput

soln:
	g++ -o solution solution.cpp
	./solution test.satoutput mitwa.subgraphs
	cat mitwa.subgraphs

clean:
	rm main
