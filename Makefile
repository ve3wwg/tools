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

all:	mktime gmktime tohex strerror timezone

mktime:	mktime.o tohex.o
	$(CXX) mktime.o -o mktime

gmktime: gmktime.o tohex.o
	$(CXX) gmktime.o -o gmktime

tohex:	tohex.o
	$(CXX) tohex.o -o tohex

strerror: strerror.o
	$(CXX) strerror.o -o strerror

timezone: timezone.o
	$(CXX) timezone.o -o timezone

ip_touint: ip_touint.o
	$(CXX) ip_touint.o -o ip_touint

to_ip4: to_ip4.o
	$(CXX) to_ip4.o -o to_ip4

cores:	
	rm -f core core.* vgcore.* vg.log.core.*

clean:	cores
	rm -f *.o

cleanlogs:
	rm -f logs/*.log logf

clobber: clean cores
	rm -f a.out errs.t mktime tohex strerror timezone
	rm -f ip_touint

# End Makefile
