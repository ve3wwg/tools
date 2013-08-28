#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int
main(int argc,char **argv) {
	int x, er;

	for ( x=1; x<argc; ++x ) {
		er = atoi(argv[x]);
		printf("Error %d: %s\n",er,strerror(er));
	}		
	return 0;
}	
