/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:01:20 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/23 17:40:19 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		checkstr(const char *str, fstr_t *ptrfstring, va_list ap)
{

	int i;
	int go;
	int auxshift;
	i = 0;
	go = 0;
	auxshift = 0;
	//printf("Before anything: %s\n", str);
	while (str[i] != '\0')
	{
		if (go == 0)
		{
			if (str[i] != '%')
				ptrfstring->counter += write(1, &str[i], 1);
			if (str[i] == '%')
				go = 1;
		}
		/*
		if (str[i] != '%' && go == 0)
		{
			ptrfstring->counter += write(1, &str[i], 1);
			i++;
		}
		else if (str[i] == '%' && go == 0)
		{
			go = 1;
			i++;
		}
		*/
		//if (str[i] != '\0' && go == 1)
		else
		{
			// initialize struct to 0
			if (checkstr_argorder(&str[i], ptrfstring))
				i += ft_strlen(ptrfstring->argordervalue);
			else if (checkstr_flags(&str[i], ptrfstring));
			else if (checkstr_fwidth(&str[i], ptrfstring, &auxshift))
				i += auxshift - 1;
			else if (checkstr_precision(&str[i], ptrfstring, &auxshift))
					i += auxshift;
			else if (checkstr_length_hh(&str[i], ptrfstring))
				i++;
			else if (checkstr_length_h(&str[i], ptrfstring));
			else if (checkstr_length_l(&str[i], ptrfstring));
			else if (checkstr_length_ll(&str[i], ptrfstring))
				i++;
			else if (checkstr_length_j(&str[i], ptrfstring));
			else if (checkstr_length_t(&str[i], ptrfstring));
			else if (checkstr_length_z(&str[i], ptrfstring));
			else if (conversion_specifiers(&str[i], ptrfstring))
			{
				if (ptrfstring->convesp == 's' && !(ptrfstring->lengthmdf[2]))
					sconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'S' || ptrfstring->convesp == 's')
					lsconv(ap, ptrfstring);
				if (ptrfstring->counter == -1)
					break;
				else
				{
					initialize_struct(ptrfstring);
					auxshift = 0;
					go = 0;
				}
			}
			else
			{
				//printf("nothing here\n");
				write(1, &str[i], 1);
				go = 0;
			}
			/*if (str[i + 1] == '#')
			{
				//ptrfstring->flg_sharp = 1;
				ptrfstring->flags[0] = 1;
			}
			else if (str[i + 1] == '0')
			{
				//ptrfstring->flg_zero = 1;
				ptrfstring->flags[1] = 1;
			}
			else if (str[i + 1] == 's')
					ptrfstring->conversortype[0] = 1;
			else
				printf("HOLA\n");
				*/
		}
		//printf("len width value: %d\n", ft_nlen(ptrfstring->fwidthvalue));
		//printf("i en checkstr %d\n", i);
		if (auxshift)
			auxshift = 0;
		i++;
	}
}
