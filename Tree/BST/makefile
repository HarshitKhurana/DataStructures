CFLAGS=-std=c++11 -Wall -O2

all: BSTree

BSTree: main.o BSTree.o
		$(CXX) $(CFLAGS) main.o -o BSTree

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp

bTree.o: BTNode.h 
		$(CXX) $(CFLAGS) -c BSTree.cpp

clean:
		rm -f *.o BSTree

rm:
		rm -f *.o BSTree

run:
		./BSTree
