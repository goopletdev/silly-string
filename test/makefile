CC = gcc
CFLAGS = -Wall -Wextra -Wno-override-init -g -std=c99 -I. -I../src -I./Unity/src
TARGET = silly-string-test

SOURCES = silly-string-test.c ../src/silly-string.c Unity/src/unity.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $^

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean
