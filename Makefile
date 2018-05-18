CC = g++
CFLAGS = -c -Wall -Iinclude -O3 -Wc++11-extensions
LDFLAGS =
SRC = src/
SOURCES = $(SRC)main.cpp $(SRC)z80.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = gba
OUTDIR = out/

all: setup build

setup:
	mkdir -p $(OUTDIR)

build: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(subst src/,out/,$(OBJECTS)) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $(subst src/,out/,$@)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)