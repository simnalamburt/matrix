### Setting
TARGET = matrix
LIBS = -lncurses

CXX = g++
CPPFLAGS = -g -Wall -std=c++11

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.hpp)

### Script
default: $(TARGET)
all: default

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -Wall $(LIBS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)

.PHONY: default all clean
.PRECIOUS: $(TARGET) $(OBJECTS)
