//////////////////////////////////////////////////////////////////////
// to_ip4.cpp	-- Utility to convert uint32 to IP4 address
// Date: Thu Oct 31 11:50:22 2013   (C) datablocks.net
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include <arpa/inet.h>

static void
report(const char *u32) {
	char *ep;
	uint32_t ip = strtoul(u32,&ep,10);	

	in_addr a;
	a.s_addr = htonl(ip);
	char str[INET_ADDRSTRLEN+1];
	
	inet_ntop(AF_INET,&a,str,INET_ADDRSTRLEN);
	str[INET_ADDRSTRLEN] = 0;

	printf("%u\t%s\n",ip,str);
}

int
main(int argc,char **argv) {

	for ( int x=1; x<argc; ++x )
		report(argv[x]);

	return 0;
}

// End geocity.cpp
