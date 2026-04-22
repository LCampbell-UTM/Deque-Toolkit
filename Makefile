CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

all: program

program: main.o deque.o
	$(CXX) $(CXXFLAGS) -o program main.o deque.o

main.o: main.cpp deque.h
	$(CXX) $(CXXFLAGS) -c main.cpp

deque.o: deque.cpp deque.h
	$(CXX) $(CXXFLAGS) -c deque.cpp

clean:
	rm -f *.o program