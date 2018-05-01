/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:01:08 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/30 19:06:39 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
char *onebyte(unsigned int *wstr)
{
	return ((char *)wstr);
}

char *twobytes(unsigned int *wstr)
{
	char *twobytestr;

	//printf("join twobytes\n");
	twobytestr = ft_strnew(2);
	twobytestr[0] = ((*wstr << 21) >> 27) | 0xc0;
	twobytestr[1] = ((*wstr << 26) >> 26) | 0x80;
	return (twobytestr);
}

char *threebytes(unsigned int *wstr)
{
	char *threebytestr;

	threebytestr = ft_strnew(3);
	threebytestr[0] = ((*wstr << 16) >> 28) | 0xe0;
	threebytestr[1] = ((*wstr << 20) >> 26) | 0x80;
	threebytestr[2] = ((*wstr << 26) >> 26) | 0x80;
	return (threebytestr);
}

char *fourbytes(unsigned int *wstr) {
	char *fourbytestr;

	fourbytestr = ft_strnew(4);
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
		if ((wstr[i] >= 0xd800 && wstr[i] <= 0xdfff))
			return (-1);
		if (wstr[i] < 0x80)
			counter++;
		else if (wstr[i] < 0x800)
			counter += 2;
		else if (wstr[i] < 0x10000)
			counter += 3;
		else if (wstr[i] < 0x110000)
			counter += 4;
		else
			return (-1);
		i++;
	}
	return (counter);
}

void	encodebytes(unsigned int *wstr, char *newstr)
{
	int i;
	int j;
	char *retrstr;

	i = 0;
	j = 0;
	retrstr = NULL;
	while (wstr[i])
	{
		if (wstr[i] < 0x0080)
			//newstr[j++] = onebyte(&wstr[i++]);
			ft_strncat(newstr, onebyte(&wstr[i++]), 1);
		else if (wstr[i] < 0x0800)
		{
			//printf("join 2 bytes\n");
			ft_strncat(newstr, retrstr = twobytes(&wstr[i++]), 2);
		}
		else if (wstr[i] < 0x10000)
			ft_strncat(newstr, retrstr = threebytes(&wstr[i++]), 3);
		else
			ft_strncat(newstr, retrstr = fourbytes(&wstr[i++]), 4);
		if (retrstr)
			ft_strdel(&retrstr);
	}
}

char	*utf8conv(unsigned int *wstr)
{
	int counter;
	char *newstr;

	counter = 0;
	if ((counter = bytesutf8(wstr)) == -1)
		return (NULL);
	//if (!counter)
	//	return (NULL);
	newstr = ft_strnew(bytesutf8(wstr));
	//printf("counter es %d", counter);
	encodebytes(wstr, newstr);
	return (newstr);
}
