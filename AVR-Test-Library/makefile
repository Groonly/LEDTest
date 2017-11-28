SRC_FILES1=\
  ../Libs/unity/src/unity.c \
  ../Libs/unity/extras/fixture/src/unity_fixture.c \

SOURCES=$(wildcard *.c) $(SRC_FILES1)
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(SOURCES:.c=.h)

CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

test: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o test

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES);

clean:
	rm \*.exe
	rm \*.o

run:
	./test.exe
