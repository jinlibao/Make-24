cc = gcc
CC = g++
CFLAG = --std=c11 -Wall -O3
CCFLAG = --std=c++17 -Wall -O3
EXECFOLDER = ../exec

ALLPROGS = make_24_c make_24_cc

make_24_cc: make_24.cc
	$(CC) $(CCFLAG) -o $(EXECFOLDER)/$@ $<

make_24_c: make_24.c
	$(cc) $(CFLAG) -o $(EXECFOLDER)/$@ $<

clean:
	rm -rf $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)

distclean:
	rm -rf $(ALLPROGS) $(EXECFOLDER)/$(ALLPROGS) $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)
