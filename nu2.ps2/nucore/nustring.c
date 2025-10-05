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


