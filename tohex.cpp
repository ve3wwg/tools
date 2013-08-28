#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc,char **argv) {
	unsigned long ulv;

	for ( int x=1; x<argc; ++x ) {
		ulv = strtoul(argv[x],0,10);
		printf("%2d  %9ld  0x%lX\n",
			x,ulv,ulv);
	}

	return 0;
}
