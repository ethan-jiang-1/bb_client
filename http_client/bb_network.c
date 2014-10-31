
#include "bb_porting.h"
#include "bb_network.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

/*
	Retrieves the IP adress of a hostname
*/
uint32_t  bb_hostname_to_ip(char *hostname)
{
	struct hostent *h = NULL;
	struct in_addr **addr_list = NULL;

	h = gethostbyname((const char*)hostname);
	if (h == NULL)
		return 0;

	addr_list = (struct in_addr **) h->h_addr_list;
	if (addr_list == NULL)
		return 0;

	struct in_addr ip;
	ip = *addr_list[0];

	printf("address: %s",inet_ntoa(ip) );

	return (uint32_t)ip.s_addr;
}

/*
addr_list = (struct in_addr **) he->h_addr_list;
for(i = 0; addr_list[i] != NULL; i++)
{
	//struct in_addr* cur_addr = addr_list[i];
	//Return the first one;
	printf("address: %s",inet_ntoa(*addr_list[i]) );
}
*/
