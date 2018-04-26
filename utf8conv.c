#include "includes/ft_printf.h"

int		utf8conv(wchar_t *wstr)
{
	int counter;
	unsigned char *newstr;

	counter = 0;
	while (*wstr++)
	{
		if (*wstr < 0x0080)
			counter++;
		else if (*wstr < 0x0800)
			counter += 2;
		else if (*wstr < 0x10000)
			counter += 3;
		else
			counter += 4;
	}
	newstr = ft_strnew(counter);

