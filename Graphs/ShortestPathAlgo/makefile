CFLAGS=-std=c++11 -Wall -O2 -Wsign-compare

all: shortestPath

install: shortestPath

shortestPath: main.o graph.o
		$(CXX) $(CFLAGS) main.o graph.o -o shortestPath

main.o: main.cpp 
		$(CXX) $(CFLAGS) -c main.cpp

graph.o: graph.h bellmanFord.h dijkastra.h floydWarshall.h  
		$(CXX) $(CFLAGS) -c graph.cpp

clean:
		rm -f *.o shortestPath

rm:
		rm -f *.o shortestPath

run:
		./shortestPath
