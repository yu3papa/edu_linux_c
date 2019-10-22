##
##		Kim Soo Hyun(@")
##
include .config

PLATFORM = 
CC = $(PLATFORM)gcc

all : app1
app1 :
	cd src; make CC=$(CC)
	cp src/app1_* .

distclean: clobber
mrproper: clobber
clobber: 
	-cd src; make clobber
	-rm -f app1_*
	-rm -f .config

clean :
	-cd src; make clean
	-rm -f app1_*

