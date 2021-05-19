cc = gcc
CC = g++
CFLAG = --std=c11 -Wall -O2
CCFLAG = --std=c++17 -Wall -O2

EXT = *.cc
SRC = $(wildcard $(EXT))

ALLPROGS = make_24_c $(basename $(SRC))

all: $(ALLPROGS)

%: %.cc
	$(CC) $(CCFLAG) -o $@ $<

make_24_c: make_24.c
	$(cc) $(CFLAG) -o $@ $<

run: game24 game24_2 make_24
	\time ./game24 < ../data/game24.in > ../data/game24.txt
	\time ./game24_2 < ../data/game24.in > ../data/game24_2.txt
	\time ./make_24 < ../data/game24.in > ../data/game24_3.txt

clean:
	rm -rf $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)

distclean:
	rm -rf $(ALLPROGS) $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)
