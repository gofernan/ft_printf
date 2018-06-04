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

int				conversors(const char *str, t_fstr *pfs, int *i)
{
	if (pfs->conv == 's' && !(pfs->lengthmdf[2]))
		sconv(pfs);
	else if (pfs->conv == 'S' || pfs->conv == 's')
		lsconv(pfs);
	else if (pfs->conv == 'd' || pfs->conv == 'i' ||
			pfs->conv == 'D')
		diconv(pfs);
	else if (pfs->conv == 'u' || pfs->conv == 'U')
		uconv(pfs);
	else if (pfs->conv == 'o' || pfs->conv == 'O')
		oconv(pfs);
	else if (pfs->conv == 'X' || pfs->conv == 'x')
		xconv(pfs);
	else if (pfs->conv == 'c' && !pfs->lengthmdf[2])
		cconv(pfs);
	else if (pfs->conv == 'C' || pfs->conv == 'c')
		lcconv(pfs);
	else if (pfs->conv == 'p')
		pconv(pfs);
	else if (pfs->conv == 'b')
		bconv(pfs);
	else
		percent(str[*i], pfs);
	return (0);
}

int				checkmdfs(const char *str, t_fstr *pfs, int *i)
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

static char		*checkstr_position(const char *str, int *i)
{
	char	*pos;
	char	*poscurl;
	char	*pospercent;
	char	*posend;

	poscurl = ft_strchr(&str[*i], '{');
	pospercent = ft_strchr(&str[*i], '%');
	posend = ft_strchr(&str[*i], '\0');
	pos = pospercent;

	if (pos)
	{
		if (poscurl)
		{
			if (pos > poscurl)
				pos = poscurl;
		}
	}
	else if (poscurl)
		pos = poscurl;
	else
		pos = posend;
	return (pos);
}

int				checkstr_outside(const char *str, t_fstr *pfs, int *i)
{
	char	*pos;
	int		sum;

	if (str[*i] != '%' && str[*i] != '{')
	{
		pos = checkstr_position(str, i);
		sum = pos - &str[*i];
		pfs->lnchars += sum;
		store_write(pfs, &str[*i], &sum);
		*i += sum - 1;
	}
	else if (str[*i] == '%')
		return (1);
	else if (str[*i] == '{')
		return (2);
	return (0);
}

void			checkstr(const char *str, t_fstr *pfs)
{
	int		i;
	int		go;

	i = 0;
	go = 0;
	while (str[i] != '\0' && pfs->counter != -1)
	{
		if (go == 0)
			go = checkstr_outside(str, pfs, &i);
		else if (go == 1)
			go = checkstr_inside(str, pfs, &i);
		else
			go = checkstr_findcolor(str, pfs, &i);
		i++;
	}
}
