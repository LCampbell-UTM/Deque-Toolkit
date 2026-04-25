CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = program
OBJS = main.o deque.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp deque.h
	$(CXX) $(CXXFLAGS) -c main.cpp

deque.o: deque.cpp deque.h
	$(CXX) $(CXXFLAGS) -c deque.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
