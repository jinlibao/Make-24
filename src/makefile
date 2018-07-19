CC = gcc
CFLAG = --std=c99 -Wall
EXECFOLDER = ../exec

ALLPROGS = compute_24

compute_24: compute_24.o
	$(CC) $(CFLAG) -o $(EXECFOLDER)/$@ $<

clean:
	rm -rf $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)

distclean:
	rm -rf $(ALLPROGS) $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)
