UNITY = ..\Libs\unity\extras\fixture\src\unity_fixture.c

SOURCE = $(wildcard *.c) $(UNITY)
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(SOURCES:.c=.h)

CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

calculator_test: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o LEDTEST

%.o: %.c $(HEADERS) Makefile
	 $(CC) $(CFLAGS) -c -o $@ $<;


clean:
	rm \*.o
	rm \*.exe

run:
	calculator.exe
test:
	calculator_test.exe
