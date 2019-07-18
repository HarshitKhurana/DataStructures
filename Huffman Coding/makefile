CFLAGS=-std=c++11 -Wall -O2

all: huffMan

install: huffMan

huffMan: HashMap.o main.o
		$(CXX) $(CFLAGS) main.o -o huffMan

main.o: main.cpp Huffman.cpp
		$(CXX) $(CFLAGS) -c main.cpp Huffman.cpp

huffMan.o: Huffman.h BTNode.h Comparison.h Huffman.cpp 
		$(CXX) $(CFLAGS) -c huffMan.cpp

clean:
	rm -f *.o huffMan

rm:
	rm -f *.o huffMan

run:
		./huffMan
