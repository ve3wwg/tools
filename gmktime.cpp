//////////////////////////////////////////////////////////////////////
// gmktime.cpp -- Produce Data/Time from utime value in UTC
// Date: Wed Oct  9 11:35:55 2013  Warren Gay
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Each command line argument is converted to time_t, and then
// reported in YYYY-MM-DD HH:MM:SS
//////////////////////////////////////////////////////////////////////

int
main(int argc,char **argv) {
	char buf[128];

	for ( int x=1; x<argc; ++x ) {
		time_t utime = atol(argv[x]);
		struct tm td;

		gmtime_r(&utime,&td);
		strftime(buf,sizeof buf,"%Y-%m-%d %H:%M:%S",&td);
		printf("%12ld  %s\n",(long)utime,buf);
	}

	return 0;
}

// End gmktime.cpp
