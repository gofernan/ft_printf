/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:01:20 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:04:59 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		checkstr(const char *str, fstr_t *ptrfstring, va_list ap)
{
	int		i;
	int		go;
	int		auxshift;
	int		counter;
	char	*pos;
	i = 0;
	go = 0;
	auxshift = 0;
	counter = 0;
	pos = NULL;
	while (str[i] != '\0')
	{
		if (go == 0)
		{
			if (str[i] != '%')
			{
				if ((pos = ft_strchr(&str[i], '%')))
				{
					//if (!(ptrfstring->literalv = ft_strnew(pos - &str[i])))
					//	exit(EXIT_FAILURE);
					//ptrfstring->literal = 1;
					//ft_strncpy(ptrfstring->literalv, &str[i], pos - &str[i]);
					//i += ((pos - &str[i]) - 1);
					//
					ptrfstring->literal = 1;
					ptrfstring->lnchars = pos - &str[i];
					store_write(ptrfstring, &str[i], &ptrfstring->lnchars);
					i += ptrfstring->lnchars - 1;
				}
				else
				{
					ptrfstring->lnchars = ft_strlen(&str[i]);
					store_write(ptrfstring, &str[i], &ptrfstring->lnchars);
					//ptrfstring->counter += write(1, &str[i], ft_strlen(&str[i]));
					i += ft_strlen(&str[i]) - 1;
				}
			}
			else 
			{
				if (str[i + 1] == '\0' && ptrfstring->literal == 1)
				{
					ptrfstring->counter += write(1, ptrfstring->literalv, ft_strlen(ptrfstring->literalv));
					ft_strdel(&ptrfstring->literalv);
				}
				else
					go = 1;
			}
		}
		else
		{
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
			else if (checkstr_length_q(&str[i], ptrfstring));
			else if (conversion_specifiers(&str[i], ptrfstring))
			{
				if (ptrfstring->convesp == 's' && !(ptrfstring->lengthmdf[2]))
					sconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'S' || ptrfstring->convesp == 's')
					lsconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'd' || ptrfstring->convesp == 'i' ||
						ptrfstring->convesp == 'D')
					diconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'u' || ptrfstring->convesp == 'U')
					uconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'o' || ptrfstring->convesp == 'O')
					oconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'X' || ptrfstring->convesp == 'x')
					xconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'c' && !ptrfstring->lengthmdf[2])
					cconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'C' || ptrfstring->convesp == 'c')
					lcconv(ap, ptrfstring);
				else if (ptrfstring->convesp == 'p')
					pconv(ap, ptrfstring);
				if (ptrfstring->counter == -1)
				{
				//if (ptrfstring->literal)
				//	ft_strdel(&ptrfstring->literalv);
				break;
				}
				else
				{
				//	if (ptrfstring->literal)
				//		ft_strdel(&ptrfstring->literalv);
					initialize_struct(ptrfstring);
					go = 0;
				}
			}
			else
			{
				percent(str[i], ptrfstring);
				if (ptrfstring->counter == -1)
				{
					//if (ptrfstring->literal)
					//	ft_strdel(&ptrfstring->literalvalue);
					break;
				}
				else
				{
				//	if (ptrfstring->literal)
				//		ft_strdel(&ptrfstring->literalv);
					initialize_struct(ptrfstring);
					go = 0;
				}
			}
			if (auxshift) //provisional
				auxshift = 0;
		}
		i++;
	}
}
