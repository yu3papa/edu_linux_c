##
##		Kim Soo Hyun(@")
##
include .config

PLATFORM = 
CC = $(PLATFORM)gcc

all : app2
app2 :
	cd src; make CC=$(CC)
	cp src/app2_* .

distclean: clobber
mrproper: clobber
clobber: 
	-cd src; make clobber
	-rm -f app2_*
	-rm -f .config

clean :
	-cd src; make clean
	-rm -f app2_*

