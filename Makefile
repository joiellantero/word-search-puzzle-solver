CSRC=CPS.c CPS_lib.c
PROGNAME=cps
CC=gcc
CFLAGS=-W -Wall -Werror
LFLAGS=-lm
OBJECTS=$(CSRC)
all: $(PROGNAME)
.PHONY: clean
$(PROGNAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJECTS) -o $(PROGNAME)
clean:
	rm -f $(OBJECTS)
	rm -f $(PROGNAME)
