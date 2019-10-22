##
##		Kim Soo Hyun(@")
##
include .config

PLATFORM = 
CC = $(PLATFORM)gcc

all : test
test :
	cd libtest; make CC=$(CC)
	cp libtest/libtest.* .

distclean: clobber
mrproper: clobber
clobber: 
	-cd libtest; make clobber
	-rm -f libtest.*
	-rm -f .config

clean : clean_libtest

clean_libtest :
	-cd libtest; make clean
	-rm -f libtest.*

