CFLAGS=-std=c++11 -Wall -O2

all: pQueue

install: pQueue

pQueue: main.o
		$(CXX) $(CFLAGS) main.o -o pQueue

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o pQueue

rm:
	rm -f *.o pQueue

run:
		./pQueue
