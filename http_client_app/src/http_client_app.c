/*
 ============================================================================
 Name        : http_client_app.c
 Author      : ethan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "bb_porting.h"
#include "bb_httpclient.h"

int main(void) {

	char *str = 0;

	str = bb_urlencode("www.baidu.com");

	puts(str);


	BB_HTTP_RESPONSE*hr = 0;

	hr = http_get("http://www.baidu.com",0);

	http_response_free(hr);

	return EXIT_SUCCESS;
}
