all : mytask mydaemon 01 02-1 02-2 03 04 05 06

mytask:
	gcc -o mytask mytask.c
mydaemon:
	gcc -o mydaemon mydaemon.c
01:
	gcc -o 01 01.mysystem.c
02-1:
	gcc -o 02-1 02-1.myfork.c
02-2:
	gcc -o 02-2 02-2.myfork.c
03:
	gcc -o 03 03.mywait.c
04:
	gcc -o 04 04.mywaitpid.c
05:
	gcc -o 05 05.myexit.c
06:
	gcc -o 06 06.myexecl.c

clean :
	rm -f mytask mydaemon 01 02-1 02-2 03 04 05 06
	