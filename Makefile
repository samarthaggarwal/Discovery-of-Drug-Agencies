all: main.cpp 
	g++ -o main main.cpp graph.cpp
	./main test.graph
	# minisat test.satoutput b.txt
	# cat b.txt
	# g++ -o solution solution.cpp
	# ./solution b.txt

mini:
	minisat test.satoutput b.txt
	cat b.txt
