CC=g++
CFLAGS=-c -Wall -Werror
LDFLAGS=-lglut -lGL -lGLU
SOURCES=main.cpp App.cpp Keyboard.cpp Mouse.cpp Camera.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) 
