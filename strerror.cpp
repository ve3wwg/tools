//////////////////////////////////////////////////////////////////////
// strerror.cpp -- Convert command line numeric to strerror message
// Date: Fri Sep 27 10:31:42 2013   (C) datablocks.net
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//////////////////////////////////////////////////////////////////////
// Each command line argument is converted to an int (errno) and
// then reported from strerror() as a message.
//////////////////////////////////////////////////////////////////////

int
main(int argc,char **argv) {
	int x, er;

	for ( x=1; x<argc; ++x ) {
		er = atoi(argv[x]);
		printf("Error %d: %s\n",er,strerror(er));
	}		
	return 0;
}	

// End strerror.cpp
