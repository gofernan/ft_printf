/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:01:20 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:30:59 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			conversors(const char *str, t_fstr *pfs, va_list ap, int *i)
{
	if (pfs->conv == 's' && !(pfs->lengthmdf[2]))
		sconv(ap, pfs);
	else if (pfs->conv == 'S' || pfs->conv == 's')
		lsconv(ap, pfs);
	else if (pfs->conv == 'd' || pfs->conv == 'i' ||
			pfs->conv == 'D')
		diconv(ap, pfs);
	else if (pfs->conv == 'u' || pfs->conv == 'U')
		uconv(ap, pfs);
	else if (pfs->conv == 'o' || pfs->conv == 'O')
		oconv(ap, pfs);
	else if (pfs->conv == 'X' || pfs->conv == 'x')
		xconv(ap, pfs);
	else if (pfs->conv == 'c' && !pfs->lengthmdf[2])
		cconv(ap, pfs);
	else if (pfs->conv == 'C' || pfs->conv == 'c')
		lcconv(ap, pfs);
	else if (pfs->conv == 'p')
		pconv(ap, pfs);
	else if (pfs->conv == 'b')
		bconv(ap, pfs);
	else
		percent(str[*i], pfs);
	return (0);
}

int			checkmdfs(const char *str, t_fstr *pfs, int *i)
{
	if (checkstr_length_hh(&str[*i], pfs))
		(*i)++;
	else if (checkstr_length_h(&str[*i], pfs))
		;
	else if (checkstr_length_l(&str[*i], pfs))
		;
	else if (checkstr_length_ll(&str[*i], pfs))
		(*i)++;
	else if (checkstr_length_j(&str[*i], pfs))
		;
	else if (checkstr_length_t(&str[*i], pfs))
		;
	else if (checkstr_length_z(&str[*i], pfs))
		;
	else if (checkstr_length_q(&str[*i], pfs))
		;
	else
		return (0);
	return (1);
}

int			checkstr_outside(const char *str, t_fstr *pfs, va_list ap, int *i)
{
	char	*pos;
	char	colorchar;

	if (str[*i] != '%')
	{
		//if (str[*i] == '{')
		//	checkstr_colors(str, pfs, *i);
		if ((pos = ft_strchr(&str[*i], '%')))
		{
			pfs->lnchars = pos - &str[*i];
			store_write(pfs, &str[*i], &pfs->lnchars);
			*i += pfs->lnchars - 1;
		}
		else
		{
			pfs->lnchars = ft_strlen(&str[*i]);
			store_write(pfs, &str[*i], &pfs->lnchars);
			*i += ft_strlen(&str[*i]) - 1;
		}
	}
	else
		return (1);
	return (0);
}

int			checkstr_inside(const char *str, t_fstr *pfs, va_list ap, int *i)
{
	int auxshift;

	auxshift = 0;
	if (checkstr_argorder(&str[*i], pfs, &auxshift))
	{
		if (!pfs->argov)
		{
			*i += auxshift - 2;
			initialize_struct(pfs);
			return (0);
		}
		*i += auxshift - 1;
	}
	else if (checkstr_flags(&str[*i], pfs))
		;
	else if (checkstr_fwidth(&str[*i], pfs, &auxshift))
		*i += auxshift;
	else if (checkstr_prec(&str[*i], pfs, &auxshift))
		*i += auxshift;
	else if (checkmdfs(str, pfs, i))
		;
	else
	{
		if (convsp(&str[*i], pfs) && !pfs->argo && !pfs->fwidth_as && !pfs->prec_as)
			(pfs->argov)++;
		if (pfs->precheck)
			store_arglist(pfs);
		else
			conversors(str, pfs, ap, i);
		if (pfs->counter != -1)
		{
			initialize_struct(pfs);
			return (0);
		}
	}
	return (1);
}

void		checkstr(const char *str, t_fstr *pfs, va_list ap)
{
	int		i;
	int		go;

	i = 0;
	go = 0;
	while (str[i] != '\0' && pfs->counter != -1)
	{
		if (go == 0)
			go = checkstr_outside(str, pfs, ap, &i);
		else
			go = checkstr_inside(str, pfs, ap, &i);
		i++;
	}
}
