CFLAGS=-std=c++11 -Wall -O2

all: graph

install: graph

graph: main.o graph.o
		$(CXX) $(CFLAGS) main.o graph.o -o graph

main.o: main.cpp 
		$(CXX) $(CFLAGS) -c main.cpp

graph.o: graph.h  bfs.h dfs.h 
		$(CXX) $(CFLAGS) -c graph.cpp

clean:
		rm -f *.o graph

rm:
		rm -f *.o graph

run:
		./graph
