 all: main.cpp 
	  g++ -o main main.cpp graph.cpp
	  ./main test.graph
