CC = gcc
CFLAG = --std=c99 -Wall

ALLPROGS = compute_24

compute_24: compute_24.o
	$(CC) $(CFLAG) -o $@ $<

clean:
	rm -rf $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)

distclean:
	rm -rf $(ALLPROGS) $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)
