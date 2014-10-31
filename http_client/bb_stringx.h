/*
 * bb_stringx.h
 *
 *  Created on: Oct 31, 2014
 *      Author: ethan
 */

#ifndef BB_STRINGX_H_
#define BB_STRINGX_H_


/*
	Checks if one string contains another string
*/
int str_contains(const char *haystack, const char *needle);
char *str_replace(char *search , char *replace , char *subject);
char* get_until(char *haystack, char *until);
char *str_ndup (const char *str, size_t max);

#endif /* BB_STRINGX_H_ */
