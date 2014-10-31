#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

//#define NULL (void*)0

void print_ip_by_hostname1(char *host_name)
{
    char *ptr = 0;
    char **pptr;
    struct hostent *hptr = 0;
    char str[32];

    puts("\ntest: print_ip_by_hostname1\n");

    // 调用gethostbyname()。调用结果都存在hptr中
    if ((hptr = gethostbyname(host_name)) == (void*)0)
    {
        printf("gethostbyname error for host:%s\n", ptr);
        return;
    }
    // 将主机的规范名打出来
    printf("official hostname:%s\n",hptr->h_name);
    // 主机可能有多个别名，将所有别名分别打出来
    for (pptr = hptr->h_aliases; *pptr != (void*)0; pptr++)
        printf(" alias:%s\n",*pptr);
    // 根据地址类型，将地址打出来
    switch(hptr->h_addrtype)
    {
    case AF_INET:
    case AF_INET6:
        pptr=hptr->h_addr_list;
        // 将刚才得到的所有地址都打出来。其中调用了inet_ntop()函数
        for(;*pptr!=(void*)0;pptr++) {
        	str[0]=0;
        	//char *address = inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str));
            printf(" address:%s\n", inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
        }
        break;
    default:
        printf("unknown address type\n");
        break;
    }


}

void print_ip_by_hostname2(char * hostname)
{
	struct hostent *he;
	struct in_addr **addr_list;
	int i;
	//char str[100];

    puts("\ntest: print_ip_by_hostname2\n");

	if ( (he = gethostbyname( hostname ) ) == NULL)
	{
		printf("error");
	}

	addr_list = (struct in_addr **) he->h_addr_list;

	for(i = 0; addr_list[i] != NULL; i++)
	{
		//struct in_addr* cur_addr = addr_list[i];
		//Return the first one;
		printf("address: %s",inet_ntoa(*addr_list[i]) );
	}

}

void inet_tests()
{
	struct in_addr addr1,addr2;
	ulong l1,l2;

	puts("\ntest: inet_test\n");

	l1= inet_addr("192.168.0.74");
	l2 = inet_addr("211.100.21.179");
	memcpy(&addr1, &l1, 4);
	memcpy(&addr2, &l2, 4);
	printf("%s : %s\n", inet_ntoa(addr1), inet_ntoa(addr2));
	printf("%s\n", inet_ntoa(addr1));
	printf("%s\n", inet_ntoa(addr2));
}


void get_host_by_name_tests()
{
	inet_tests();

	print_ip_by_hostname1("www.baidu.com");
	print_ip_by_hostname2("www.baidu.com");
}



