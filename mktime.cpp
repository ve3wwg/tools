//////////////////////////////////////////////////////////////////////
// mktime.cpp -- Produce Data/Time from utime value
// Date: Wed Aug 28 11:00:31 2013   
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int
main(int argc,char **argv) {
	char buf[128];

	for ( int x=1; x<argc; ++x ) {
		time_t utime = atol(argv[x]);
		struct tm td;

		localtime_r(&utime,&td);
		strftime(buf,sizeof buf,"%Y-%m-%d %H:%M:%S",&td);
		printf("%12ld  %s\n",(long)utime,buf);
	}

	return 0;
}

// End mktime.cpp
