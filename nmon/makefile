CC=gcc
CFLAGS=-g -O3 -Wall
LDFLAGS=-lncurses -lm
FILE=lmon.c

all: nmon_x86_rhel7

nmon_x86_rhel7: $(FILE)
	$(CC) -o nmon_x86_rhel7 $(FILE) $(CFLAGS) $(LDFLAGS) -D X86 -D RHEL7
	
clean:
	rm -fr lmon.o nmon_x86_rhel7