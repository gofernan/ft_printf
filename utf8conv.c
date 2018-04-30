#include "includes/ft_printf.h"
unsigned char onebyte(unsigned int *wstr)
{
	return ((unsigned char)*wstr);
}

unsigned char *twobytes(unsigned int *wstr)
{
	unsigned char *twobytestr;

	twobytestr = ft_memalloc(3);
	ft_memset(twobytestr, 0, 3);
	twobytestr[0] = ((*wstr << 21) >> 27) | 0xc0;
	twobytestr[1] = ((*wstr << 26) >> 26) | 0x80;
	return (twobytestr);
}

unsigned char *threebytes(unsigned int *wstr)
{
	unsigned char *threebytestr;

	threebytestr = ft_memalloc(4);
	ft_memset(threebytestr, 0, 4);
	threebytestr[0] = ((*wstr << 16) >> 28) | 0xe0;
	threebytestr[1] = ((*wstr << 20) >> 26) | 0x80;
	threebytestr[2] = ((*wstr << 26) >> 26) | 0x80;
	return (threebytestr);
}

unsigned char *fourbytes(unsigned int *wstr)
{
	unsigned char *fourbytestr;

	fourbytestr = ft_memalloc(5);
	ft_memset(fourbytestr, 0, 5);
	fourbytestr[0] = ((*wstr << 11) >> 29) | 0xf0;
	fourbytestr[1] = ((*wstr << 14) >> 26) | 0x80;
	fourbytestr[2] = ((*wstr << 20) >> 26) | 0x80;
	fourbytestr[3] = ((*wstr << 26) >> 26) | 0x80;
	return (fourbytestr);
}

int		bytesutf8(unsigned int *wstr)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (wstr[i])
	{
		if (wstr[i] < 0x80)
			counter++;
		else if (wstr[i] < 0x800)
			counter += 2;
		else if (wstr[i] < 0x10000)
		{
			if (wstr[i] >= 0xd800 && wstr[i] <= 0xdfff)
				return (-1);
			counter += 3;
		}
		else if (wstr[i] < 0x110000)
			counter += 4;
		else
			return (-1);
		i++;
	}
	return (counter);
}

void	encodebytes(unsigned int *wstr, unsigned char *newstr)
{
	int i;
	int j;
	unsigned char *retrstr;

	i = 0;
	j = 0;
	retrstr = NULL;
	while (wstr[i])
	{
		if (wstr[i] < 0x0080)
			newstr[j++] = onebyte(&wstr[i++]);
		else if (wstr[i] < 0x0800)
		{
			//printf("join 2 bytes\n");
			ft_strncat((char *)newstr, (char *)(retrstr = twobytes(&wstr[i++])), 2);
		}
		else if (wstr[i] < 0x10000)
			ft_strncat((char *)newstr, (char *)(retrstr = threebytes(&wstr[i++])), 3);
		else
			ft_strncat((char *)newstr, (char *)(retrstr = fourbytes(&wstr[i++])), 4);
		if (retrstr)
			ft_memdel((void *)&retrstr);
	}
}

unsigned char	*utf8conv(unsigned int *wstr)
{
	int counter;
	unsigned char *newstr;

	counter = 0;
	if ((counter = bytesutf8(wstr)) == -1)
		return (NULL);
	if (!counter)
		return (NULL);
	//newstr = ft_strnew(bytesutf8(wstr));
	newstr = ft_memalloc(bytesutf8(wstr) + 1);
	ft_memset(newstr, 0, bytesutf8(wstr) + 1);
	encodebytes(wstr, newstr);
	return (newstr);
}
