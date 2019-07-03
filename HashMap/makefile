CFLAGS=-std=c++11 -Wall

all: hashMapCode

hashMapCode: hashMap.o main.o
		$(CXX) $(CFLAGS) main.o -o hashMap

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp

hashMap.o: hashNode.h hashMap.h hashMap.cpp
		$(CXX) $(CFLAGS) -c hashMap.cpp

clean:
	rm -f *.o hashMapCode

rm:
	rm -f *.o hashMapCode

run:
		./hashMapCode
