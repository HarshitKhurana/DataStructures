CFLAGS=-std=c++11 -Wall -O2

all: hashMapCode

install: hashMapCode

hashMapCode: HashMap.o main.o
		$(CXX) $(CFLAGS) main.o -o hashMapCode

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp

hashMap.o: HashNode.h HashMap.h HashMap.cpp
		$(CXX) $(CFLAGS) -c hashMap.cpp

clean:
	rm -f *.o hashMapCode

rm:
	rm -f *.o hashMapCode

run:
		./hashMapCode
