CFLAGS=-std=c++11 -Wall -O2

all: Huffman

install: Huffman

Huffman: Huffman.o main.o
		$(CXX) $(CFLAGS) main.o -o Huffman

main.o: main.cpp Huffman.o
		$(CXX) $(CFLAGS) -c main.cpp 

Huffman.o: Huffman.h BTNode.h Comparison.h Huffman.cpp 
		$(CXX) $(CFLAGS) -c Huffman.cpp -o Huffman.o

clean:
	rm -f *.o Huffman

rm:
	rm -f *.o Huffman

run:
		./Huffman
