all: main.cpp 
	g++ -o main main.cpp graph.cpp -std=c++11
	./main test.graph
	./minisat test.satinput test.satoutput
	cat test.satoutput
	g++ -o solution solution.cpp
	./solution test.satoutput

mini:
	minisat test.satoutput b.txt
	cat b.txt

clean:
	rm main
