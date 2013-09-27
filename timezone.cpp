//////////////////////////////////////////////////////////////////////
// timezone.cpp -- Print timezone info
// Date: Thu Aug 29 09:19:37 2013   (C) datablocks.net
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Reports on your timezone environment:
//
// tzname[0] = 'EST'
// tzname[1] = 'EDT'
// 
//  timezone = 18000
//  daylight = 1
// 
//  In effect: 'EDT'
// Behind UTC: 4.0 hours
//  
//////////////////////////////////////////////////////////////////////

int
main(int argc,char **argv) {
//	extern char *tzname[2];
//	extern long timezone;
//	extern int daylight;
	const double one_hour = 60.0 * 60.0;
	int x, z;

	tzset();

	for ( x=0; x<2; ++x ) {
		if ( tzname[x] )
			printf("tzname[%d] = '%s'\n",x,tzname[x]);
	}

	printf("\n timezone = %ld\n",(long)timezone);
	printf(" daylight = %d\n\n",daylight);

	z = daylight ? 1 : 0;

	printf(" In effect: '%s'\n",tzname[z] ? tzname[z] : "?");

	double hours = timezone;
	if ( daylight )
		hours -= one_hour;

	hours /= one_hour;

	printf("Behind UTC: %.1lf hours\n",hours);

	return 0;
}

// End timezone.cpp
