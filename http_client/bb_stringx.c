#include "bb_porting.h"
#include "bb_stringx.h"



/*
	Gets the offset of one string in another string
*/
int str_index_of(const char *a, char *b)
{
	char *offset = (char*)strstr(a, b);
	return offset - a;
}

/*
	Checks if one string contains another string
*/
int str_contains(const char *haystack, const char *needle)
{
	char *pos = (char*)strstr(haystack, needle);
	if(pos)
		return 1;
	else
		return 0;
}

/*
	Removes last character from string
*/
char* trim_end(char *string, char to_trim)
{
	char last_char = string[strlen(string) -1];
	if(last_char == to_trim)
	{
		char *new_string = string;
		new_string[strlen(string) - 1] = 0;
		return new_string;
	}
	else
	{
		return string;
	}
}

/*
	Concecates two strings, a wrapper for strcat from string.h, handles the resizing and copying
*/
char* str_cat(char *a, char *b)
{
	char *target = (char*)malloc(strlen(a) + strlen(b) + 1);
	strcpy(target, a);
	strcat(target, b);
	return target;
}


/*
	Replacement for the string.h strndup, fixes a bug
*/
char *str_ndup (const char *str, size_t max)
{
    size_t len = strnlen (str, max);
    char *res = (char*)malloc (len + 1);
    if (res)
    {
        memcpy (res, str, len);
        res[len] = '\0';
    }
    return res;
}

/*
	Replacement for the string.h strdup, fixes a bug
*/
char *str_dup(const char *src)
{
   char *tmp = (char*)malloc(strlen(src) + 1);
   if(tmp)
       strcpy(tmp, src);
   return tmp;
}

/*
 	Search and replace a string with another string , in a string
*/
char *str_replace(char *search , char *replace , char *subject)
{
	char  *p = NULL , *old = NULL , *new_subject = NULL ;
	int c = 0 , search_size;
	search_size = strlen(search);
	for(p = strstr(subject , search) ; p != NULL ; p = strstr(p + search_size , search))
	{
		c++;
	}
	c = ( strlen(replace) - search_size )*c + strlen(subject);
	new_subject = (char*)malloc( c );
	strcpy(new_subject , "");
	old = subject;
	for(p = strstr(subject , search) ; p != NULL ; p = strstr(p + search_size , search))
	{
		strncpy(new_subject + strlen(new_subject) , old , p - old);
		strcpy(new_subject + strlen(new_subject) , replace);
		old = p + search_size;
	}
	strcpy(new_subject + strlen(new_subject) , old);
	return new_subject;
}

/*
	Get's all characters until '*until' has been found
*/
char* get_until(char *haystack, char *until)
{
	int offset = str_index_of(haystack, until);
	return str_ndup(haystack, offset);
}

