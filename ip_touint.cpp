//////////////////////////////////////////////////////////////////////
// geocity.cpp -- Command to test GeoIPCity facility by IP
// Date: Wed Oct  9 13:44:41 2013   (C) datablocks.net
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include <arpa/inet.h>

static void
report(const char *ipaddr) {
	struct in_addr addr;

	inet_pton(AF_INET,ipaddr,&addr);

	uint32_t ip = ntohl(addr.s_addr);
	
	printf("%s\t%u\n",ipaddr,ip);
}

int
main(int argc,char **argv) {

	for ( int x=1; x<argc; ++x )
		report(argv[x]);

	return 0;
}

// End geocity.cpp
