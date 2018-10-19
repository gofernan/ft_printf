/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retr_arglist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:51:21 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/04 11:09:00 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		create_defaultv(t_args *tmpargsl, t_fstr *pfs, int *i)
{
	tmpargsl = pfs->ptrlargs;
	while (tmpargsl)
	{
		if (!tmpargsl->next)
		{
			if (!(tmpargsl->next = (t_args *)malloc(sizeof(t_args))))
				exit(EXIT_FAILURE);
			fill_defaultv(tmpargsl->next, i);
			tmpargsl = tmpargsl->next;
		}
		tmpargsl = tmpargsl->next;
	}
}

static void		go_over(t_args *tmpargsl, t_fstr *pfs, int *i, int *maxorder)
{
	while (++(*i) <= *maxorder)
	{
		while (tmpargsl)
		{
			if (tmpargsl->value != *i)
				tmpargsl = tmpargsl->next;
			else
				break ;
		}
		if (!tmpargsl)
			create_defaultv(tmpargsl, pfs, i);
		tmpargsl = pfs->ptrlargs;
	}
}

static void		retr_ap(va_list ap2, t_args *tmpargsl)
{
	if (tmpargsl->conv == 's' && tmpargsl->mdf != 2)
		tmpargsl->str = va_arg(ap2, char *);
	else if (tmpargsl->conv == 'S' || tmpargsl->conv == 's')
		tmpargsl->str = check_locale_lsconv(ap2, tmpargsl);
	else if (tmpargsl->conv == 'd' || tmpargsl->conv == 'i' ||
			tmpargsl->conv == 'D')
		tmpargsl->str = dimdfs(ap2, tmpargsl);
	else if (tmpargsl->conv == 'u' || tmpargsl->conv == 'U')
		tmpargsl->str = umdfs(ap2, tmpargsl);
	else if (tmpargsl->conv == 'o' || tmpargsl->conv == 'O')
		tmpargsl->str = omdfs(ap2, tmpargsl);
	else if (tmpargsl->conv == 'X' || tmpargsl->conv == 'x')
		tmpargsl->str = xmdfs(ap2, tmpargsl);
	else if (tmpargsl->conv == 'c' && tmpargsl->mdf != 2)
		tmpargsl->str = cconva(ap2);
	else if (tmpargsl->conv == 'C' || tmpargsl->conv == 'c')
		tmpargsl->str = check_locale_lcconv(ap2, tmpargsl);
	else if (tmpargsl->conv == 'p')
		tmpargsl->str = ft_uitoab((va_arg(ap2, uintmax_t)), 16, 0);
	else if (tmpargsl->conv == 'b')
		tmpargsl->str = ft_binary((va_arg(ap2, intmax_t)));
}

static void		store_str(va_list ap2, t_fstr *pfs, t_args *tmpargsl,
		int *maxorder)
{
	int i;

	i = 1;
	while (i <= *maxorder)
	{
		while (tmpargsl->value != i)
		{
			if (!(tmpargsl = tmpargsl->next))
				break ;
		}
		retr_ap(ap2, tmpargsl);
		tmpargsl = pfs->ptrlargs;
		i++;
	}
}

void			retr_arglist(va_list ap, t_fstr *pfs)
{
	va_list ap2;
	t_args	*tmpargsl;
	int		maxorder;
	int		i;
	char	*s;

	maxorder = 1;
	i = 0;
	tmpargsl = pfs->ptrlargs;
	s = NULL;
	while (tmpargsl)
	{
		if (tmpargsl->value > maxorder)
			maxorder = tmpargsl->value;
		tmpargsl = tmpargsl->next;
	}
	tmpargsl = pfs->ptrlargs;
	go_over(tmpargsl, pfs, &i, &maxorder);
	va_copy(ap2, ap);
	store_str(ap2, pfs, tmpargsl, &maxorder);
	va_end(ap2);
}
