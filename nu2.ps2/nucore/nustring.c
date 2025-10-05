#include "nustring.h"

/*
 * @implemented
 */
void
NuStrCat(char *dst, const char *src)
{
	char c;

	if (*dst == '\0') {
		c = *src;
		while (TRUE) {
			*dst = c;
			dst++;
			c = *src;
			src++;
			if (c == '\0')
				break;
loop:
			c = *src;
		}
		return;
	}
	dst++;
	do {
		if (*dst == '\0')
			goto loop;
		dst++;
	} while (TRUE);
}

/*
 * @implemented
 */
void
NuStrCpy(char *dst, const char *src)
{
	char c;

	do {
		*dst = *src;
		dst++;
		c = *src;
		src++;
	} while (c != '\0');
}

/*
 * @implemented
 */
int
NuStrLen(const char *str)
{
	int len;
	char c;

	len = 0;
	c = *str;
	while (c != '\0') {
		str++;
		len++;
		c = *str;
	}

	return len;
}

char *
NuStrStr(const char *haystack, const char *needle)
{
	char c;
	char *needle_tmp, *haystack_tmp;

	c = *haystack;
	do {
		if (c == '\0')
			return NULL;
		if ((long)*needle == 0)
			return haystack;
		if ((long)(int)*haystack == 0)
			c = *needle;
		else if ((long)(int)*haystack == (long)*needle) {
			needle_tmp = needle + 1;
			haystack_tmp = haystack;
			while (TRUE) {
				haystack_tmp++;
				if (*needle_tmp == '\0')
					return haystack;
				if (*haystack_tmp == '\0') {
					c = *needle_tmp;
					goto loop;
				}
				if (*haystack_tmp != *needle_tmp)
					break;
				needle_tmp++;
			}
			c = *needle_tmp;
		} else
			c = *needle;
loop:
		if (c == '\0')
			return haystack;
		haystack++;
		c = *haystack;
	} while (TRUE);
}
