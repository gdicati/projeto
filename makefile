CC=gcc
CFLAGS=-c -Wall 
LDFLAGS=-lcurl -ljansson  
SOURCES=$(wildcard *.c)
HEADERS=$(wildcard *.h)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=medalcollection

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clear:
	rm -rf $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)
