
#define the C compiler
CC=gcc

CFLAGS = -Wall -Wextra -g -O3 --std=c11 -pedantic 

SOURCEFILES := $(wildcard *.c) 
HEADERFILES := $(wildcard *.h)

.PHONY: depend clean help 

all: sort_lines

sort_lines: $(SOURCEFILES)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LFLAGS) $(LIBS)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJS) $(LFLAGS) $(LIBS)

# target: help - Displays some help and the available targets.
help:
	@egrep "^# target:" Makefile

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r main sort_lines
