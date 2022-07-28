# Makefile.am - use automake to generate Makefile.in

AM_CXFLAGS = $(INIT_CFLAGS)

bin_PROGRAMS = test_program 
test_program_SOURCES = main.cpp

all:

clean-local:
	$(RM) Makefile
	$(RM) Makefile.in
	$(RM) aclocal.m4
	$(RM) ar-lib
	$(RM) compile
	$(RM) compare_package 
	$(RM) config.*
	$(RM) configure
	$(RM) configure~
	$(RM) depcomp
	$(RM) install-sh
	$(RM) ltmain.sh
	$(RM) libtool
	$(RM) missing 
	$(RM) *.o 
	$(RM) $(bin_PROGRAMS)
	rm -rf .deps 
	rm -rf .libs
	rm -rf autom4te.cache
	rm -rf m4 
