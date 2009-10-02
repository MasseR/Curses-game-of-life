CC=gcc
LIBS=-lncurses
FLAGS=$(LIBS)
DEBUG=-ggdb3 -pg
trg=life

all: $(trg)

$(trg): life.o
	$(CC) $< -o $@ $(FLAGS)

life.o: life.c macros.h
	$(CC) -c -o $@ $<

.PHONY: clean

clean:
	rm -f *.o
