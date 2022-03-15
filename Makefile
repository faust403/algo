SOURCES= ./struct/singleLink-list/list.c ./struct/hash-table/hash.c ./algorithm/bubble-sort.c main.c

EXECUTABLE=main

LDFLAGS=

CC=gcc
CFLAGS=-c -Wall
OBJECTS=$(SOURCES:.c=.o)

ifdef DEBUG
CFLAGS += -ggdb -O0
else
CFLAGS += -O2
endif

all: build

build: $(SOURCES) $(EXECUTABLE)
	

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) *.o

.PHONY: clean all build
