CC=g++
CXXFLAGS=-std=c++17 -Iinclude -Llib -Wall -pedantic -s
CXXLDFLAGS=-static

TARGET=cpp17-testing

$(TARGET): clean main.o
	mkdir bin obj
	mv *.o obj
	$(CC) $(CXXFLAGS) obj/main.o -o bin/$(TARGET) $(CXXLDFLAGS)

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c $^

clean:
	rm -rf bin obj
