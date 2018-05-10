/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:49:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/05 12:29:35 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <locale.h>

void (*convstr[15])(va_list ap);
/*
void store_functions(void)
{
	int 	i;

i = 2;
	convstr[1] = "dconv";
	while (i < 14)
	{
		convstr[i] = "nofunctionyet";
		i++;
	}
	convstr[i] = 0;
	
}
*/
int check_conversions(char a)
{
	char conv[15];
	int i;

	ft_strcpy(conv, CONVERSORS);
	i = 0;
	while (conv[i] != '\0')
	{
		if (a == conv[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_printf(const char *str, ...)
{
	va_list ap;
	fstr_t fstring;
	fstr_t *ptrfstring;
	//convstr[0] = sconv;
	//char	*s;
	int		counter;
	int		i;
	//char	conv[15];

	i = 0;
	counter = 0;
	//store_functions;
	va_start(ap, str);
	ptrfstring = &fstring;
	ptrfstring->counter = 0;
	ptrfstring->buffi = 0;
	ptrfstring->lnchars = 0;
	initialize_struct(ptrfstring);
	checkstr(str, ptrfstring, ap);
	if (ptrfstring->counter != -1)
		ptrfstring->counter += write(1, ptrfstring->buff, ptrfstring->buffi);
	else
		write(1, ptrfstring->buff, ptrfstring->buffi - ptrfstring->lnchars);
	if (ptrfstring->argorder == 1)
	{
		i = ft_atoi(ptrfstring->argordervalue);
		while (--i)
		{
			va_arg(ap, char *);
		}
	}
	i = 0;
	va_end(ap);
	return (ptrfstring->counter);
}
