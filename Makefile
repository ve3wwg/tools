CXX 		= g++
CC		= gcc
INCL		= 
CXXFLAGS	= -std=c++0x -Wall $(INCL)
CFLAGS		= -Wall $(INCL)
LDFLAGS		= 
OPTZ		= -g -O0
#OPTZ		= -o6

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(OPTZ) $< -o $*.o

.c.o:
	$(CC) -c $(CFLAGS) $(OPTZ) $< -o $*.o

all:	mktime tohex strerror

mktime:	mktime.o tohex.o
	$(CXX) mktime.o -o mktime

tohex:	tohex.o
	$(CXX) tohex.o -o tohex

strerror: strerror.o
	$(CXX) strerror.o -o strerror

cores:	
	rm -f core core.* vgcore.* vg.log.core.*

clean:	cores
	rm -f *.o

cleanlogs:
	rm -f logs/*.log logf

clobber: clean cores
	rm -f a.out errs.t mktime tohex strerror

# End Makefile
