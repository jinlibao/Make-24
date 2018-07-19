CC = gcc
CFLAG = --std=c99 -wall

ALLPROGS = compute_24

compute_24: compute_24.o
	$(CC) -o $@ $<

clean:
	rm -rf $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)

distclean:
	rm -rf $(ALLPROGS) $(ALLPROGS:=.o) $(ALLPROGS:=.dSYM)
