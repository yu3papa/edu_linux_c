OBJS = test1.o test2.o test3.o
CC = gcc
CFLAGS = -c -g -Wall -O2

test: $(OBJS)
	$(CC) -o $@ $(OBJS)

test1.o: test1.c a.h b.h
	$(CC) $(CFLAGS) $<

test2.o: test2.c a.h c.h
	$(CC) $(CFLAGS) $?

test3.o: test3.c a.h b.h c.h
	$(CC) $(CFLAGS) $*.c

clean:
	rm -fr test $(OBJS)