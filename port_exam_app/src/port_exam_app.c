/*
 ============================================================================
 Name        : port_exam_app.c

 Author      : ethan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/* the main purpose of this application is for examing different system API (especially around network)
 * understand the difference between linux api and qcom api.
 */

#include <stdio.h>
#include <stdlib.h>



#include "get_host_by_name.h"


int main(void) {

	puts("few sample to test the network api for porting");


	get_host_by_name_tests();

	return EXIT_SUCCESS;
}
