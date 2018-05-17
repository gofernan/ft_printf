/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:01:20 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 19:53:24 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		conversors(const char *str, fstr_t *ptrfstring, va_list ap, int *i)
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
	else
		percent(str[*i], ptrfstring);
	return (0);
}

int		checkmdfs(const char *str, fstr_t *ptrfstring, int *i)
{
	if (checkstr_length_hh(&str[*i], ptrfstring))
		(*i)++;
	else if (checkstr_length_h(&str[*i], ptrfstring))
		;
	else if (checkstr_length_l(&str[*i], ptrfstring))
		;
	else if (checkstr_length_ll(&str[*i], ptrfstring))
		(*i)++;
	else if (checkstr_length_j(&str[*i], ptrfstring))
		;
	else if (checkstr_length_t(&str[*i], ptrfstring))
		;
	else if (checkstr_length_z(&str[*i], ptrfstring))
		;
	else if (checkstr_length_q(&str[*i], ptrfstring))
		;
	else
		return (0);
	return (1);
}

int			checkstr_outside(const char *str, fstr_t *ptrfstring, va_list ap, int *i)
{
	char *pos;
	if (str[*i] != '%')
	{
		if ((pos = ft_strchr(&str[*i], '%')))
		{
			ptrfstring->lnchars = pos - &str[*i];
			store_write(ptrfstring, &str[*i], &ptrfstring->lnchars);
			*i += ptrfstring->lnchars - 1;
		}
		else
		{
			ptrfstring->lnchars = ft_strlen(&str[*i]);
			store_write(ptrfstring, &str[*i], &ptrfstring->lnchars);
			*i += ft_strlen(&str[*i]) - 1;
		}
	}
	else
		return (1);
	return (0);
}

int			checkstr_inside(const char *str, fstr_t *ptrfstring, va_list ap, int *i)
{
	int auxshift;

	auxshift = 0;
	if (checkstr_argorder(&str[*i], ptrfstring, &auxshift))
		*i += auxshift - 1;
	else if (checkstr_flags(&str[*i], ptrfstring))
		;
	else if (checkstr_fwidth(&str[*i], ptrfstring, &auxshift))
		*i += auxshift - 1;
	else if (checkstr_precision(&str[*i], ptrfstring, &auxshift))
		*i += auxshift;
	else if (checkmdfs(str, ptrfstring, i))
		;	
	else 
	{
		conversion_specifiers(&str[*i], ptrfstring);
		conversors(str, ptrfstring, ap, i);
		if (ptrfstring->counter != -1)
		{
			initialize_struct(ptrfstring);
			return (0);
		}
	}
	return (1);
}

void		checkstr(const char *str, fstr_t *ptrfstring, va_list ap)
{
	int		i;
	int		go;

	i = 0;
	go = 0;
	while (str[i] != '\0' && ptrfstring->counter != -1)
	{
		if (go == 0)
			go = checkstr_outside(str, ptrfstring, ap, &i);
		else
			go = checkstr_inside(str, ptrfstring, ap , &i);
		i++;
	}
}
