CFLAGS=-std=c++11 -Wall -O2 -Wsign-compare

all: Trie

install: Trie

Trie: main.o Trie.o
		$(CXX) $(CFLAGS) main.o -o Trie

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp

Trie.o: Trie.h Trie.cpp
		$(CXX) $(CFLAGS) -c Trie.cpp

clean:
		rm -f *.o Trie

clear:
		rm -f *.o Trie

rm:
		rm -f *.o Trie

run:
		./Trie
