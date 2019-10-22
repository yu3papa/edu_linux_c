##
##		Kim Soo Hyun(@")
##

PLATFORM = 
CC = $(PLATFORM)gcc

all : libs prjs

libs : libtest

libtest :
	@echo "----->libtest Library Build Start..."
	cd libs/libtest; make CC=$(CC)
	@echo "----->libtest Library Build Done!!."

prjs : app1 app2

app1 :
	@echo "----->Project1 Build Start..."
	cd prj1; make CC=$(CC)
	cp prj1/app1_* .
	@echo "----->Project1 Build Done!!."

app2 :
	@echo "----->Project2 Build Start..."
	cd prj2; make CC=$(CC)
	cp prj2/app2_* .
	@echo "----->Project2 Build Done!!."



distclean: clobber
mrproper: clobber
clobber: 
	-cd libs; make clobber
	-cd prj1; make clobber
	-cd prj2; make clobber
	-rm -f app1_*
	-rm -f app2_*

clean :
	-cd libs; make clean
	-cd prj1; make clean
	-cd prj2; make clean
	-rm -f app1_*
	-rm -f app2_*

clean_libs :
	-cd libs; make clean
clean_libtest :
	-cd libs; make clean_libtest
clean_prjs :
	-cd prj1; make clean
	-cd prj2; make clean
	-rm app1_*
	-rm app2_*
clean_app1 :
	-cd prj1; make clean
	-rm app1_*
clean_app2 :
	-cd prj2; make clean
	-rm app2_*
