CC = gcc
CFLAG = --std=c11 -Wall -O3
EXECFOLDER = ../exec

ALLPROGS = make_24

make_24: make_24.o
	$(CC) $(CFLAG) -o $(EXECFOLDER)/$@ $<

clean:
	rm -rf $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)

distclean:
	rm -rf $(ALLPROGS) $(EXECFOLDER)/$(ALLPROGS) $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)
