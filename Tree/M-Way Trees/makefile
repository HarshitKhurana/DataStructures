CFLAGS=-std=c++11 -Wall -O2

all: mWayTree

install: mWayTree

mWayTree: mWayTree.o
		$(CXX) $(CFLAGS) mWayTree.o -o mWayTree

mWayTree.o: MWayTree.cpp Node.h
		$(CXX) $(CFLAGS) -c MWayTree.cpp -o mWayTree.o

clean:
	rm -f *.o mWayTree

rm:
	rm -f *.o mWayTree

run:
		./mWayTree
