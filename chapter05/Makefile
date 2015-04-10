
#define the C compiler
CC=gcc

CFLAGS = -Wall -Wextra -g -O3 --std=c11 -pedantic 


.PHONY: depend clean help 

all: sort_lines dcl undcl

sort_lines: alloc.c alloc.h lines.c lines.h numcmp.c numcmp.h qsort.c qsort.h sort_lines.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LFLAGS) $(LIBS)

dcl: dcl.c dcl.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LFLAGS) $(LIBS)

undcl: undcl.c undcl.h dcl.h
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
