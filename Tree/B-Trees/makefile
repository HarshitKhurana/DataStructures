CFLAGS=-std=c++11 -Wall

all: bTree

install: bTree

bTree: bTree.o main.o
		$(CXX) $(CFLAGS) main.o -o bTree

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp

bTree.o: BTNode.h BTree.cpp
		$(CXX) $(CFLAGS) -c BTree.cpp

clean:
		rm -f *.o bTree

rm:
		rm -f *.o bTree

run:
		./bTree
