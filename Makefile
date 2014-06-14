# Variables
TARGET = matrix

CPP = clang++
CPPFLAGS = -Wall -std=c++1y
LIBS = -lncurses

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.hpp)


# Makefile scripts
all: release

debug: CPPFLAGS += -DDEBUG -g
debug: $(TARGET)

release: CPPFLAGS += -O3
release: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CPP) $(OBJECTS) -Wall $(LIBS) -o $@

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)


# Special targets
.PHONY: all debug release clean
.PRECIOUS: $(TARGET) $(OBJECTS)
