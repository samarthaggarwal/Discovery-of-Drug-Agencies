all: main.cpp 
	g++ -o main main.cpp graph.cpp -std=c++11
	./main $1.graph
	./minisat test.satinput test.satoutput
	cat test.satoutput

soln:
	g++ -o solution solution.cpp
	./solution test.satoutput $1.subgraphs
	cat $1.subgraphs

clean:
	rm main
