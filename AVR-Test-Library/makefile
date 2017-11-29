SRC_FILES1=\
  ../unity/src/unity.c \
  ../unity/extras/fixture/src/unity_fixture.c \
	../src/LedDriver.c

SOURCES=$(wildcard *.c) $(SRC_FILES1)
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(SOURCES:.c=.h)

CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: test run

test: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o LedDriverTest

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES);


clean:
	rm \*.o
	rm \*.exe

run:
	./LedDriverTest.exe
