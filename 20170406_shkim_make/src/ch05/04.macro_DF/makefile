CC = gcc
CFLAGS = -O2 -Wall -g
LDFLAGS =

all : libtest.a test

libtest.a : lib/min.o lib/max.o
	@cd $(<D); $(AR) $(ARFLAGS) -o $@ ${^F}
	mv ${<D}/*.a .

test : test_objs
	@$(CC) $(LDFLAGS) -o $@ app/objs/*

test_objs : app/src/test1.o app/src/test2.o app/src/test3.o
	@cd ${<D}; mv $(^F) ../objs

lib/%.o : CFLAGS = -fPIC -O2 -Wall -g

clean:
	-rm -f lib/*.o
	-rm -f app/objs/*.o
	-rm  libtest.a test

