/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:49:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/03 13:33:13 by gofernan         ###   ########.fr       */
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

	strcpy(conv, CONVERSORS);
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
	convstr[0] = sconv;
	//char	*s;
	int		counter;
	int		i;
	//char	conv[15];

	i = 0;
	counter = 0;
	//store_functions;
	va_start(ap, str);
	ptrfstring = &fstring;
	initialize_struct(ptrfstring);
	checkstr(str, ptrfstring, ap);
	if (ptrfstring->argorder == 1)
	{
		i = ft_atoi(ptrfstring->argordervalue);
		printf("i despues de atoi %d\n", i);
		while (--i)
		{
			va_arg(ap, char *);
		}
	}
	i = 0;
	print_initialize(ptrfstring);
	if (ptrfstring->argordervalue == NULL)
		printf("argordervalue is NULL\n");
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			counter += write(1, &str[i], 1);
			printf("counter %d\n", counter);
			//ft_putchar(str[i]);
		}
		if (str[i] == '%')
		{
				//check_argorder(str[i]);
			if (check_conversions(str[i + 1]) != -1)
			{
				//ptrf = &convstr[check_conversions(*str)]; 
				(*convstr[check_conversions(str[i + 1])])(ap);
				//s = va_arg(ap, char *);
				//write(1, s, (ft_strlen(s) + 1));
			}
			else
				ft_putstr("conversor not recognized");
		}
		i++;
	}
	va_end(ap);
	return (counter);
}

int main(void)
{
	char *str1 = "hello";
	char *str2 = "how";
	char *str3 = "are";
	char *str4 = "you";
	char *str5 = "bye";
	char **strings;

	//ft_printf("leading string :%#hhh.745s, trailing string% 'sx %1$tzjl Xbla\n", str1, str2, str3, str4, str5);
	//printf("counter: %d\n", ft_printf("Ѫઆaᴻ"));
	//ft_printf("%d", ft_printf("Ѫઆaᴻ"));
	ft_printf("%010s", "hello how are you?Ѫ");
	//setlocale(P_ALL, "en_US.UTF-8");
	/*pep check
	int i = printf("\nHola\n%c,pizaww? %C\n", 20, -65);
	ft_putnbr(i);
	*/
	return (0);
}
