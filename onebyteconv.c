/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1byteconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:20:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:21:36 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*onebyteconv(wchar_t *wstr, t_args *tmpargsl)
{
	int		i;
	char	*casted1byte;
	int		counter;
	int		len;

	i = -1;
	/*while (wstr[++i])
	{
		if (wstr[i] > 0xff)
		{
			if (tmpargsl->prec && tmpargsl->precvalue <= i)
				break ;
			else
				return (NULL);
		}
	}*/
	while (wstr[++i])
	{
		if (wstr[i] > 0xff)
		{
			tmpargsl->validlen = i + 1;
			break;
		}
	}
	len = ft_wcslen(wstr);
	if (!(casted1byte = (char *)malloc(sizeof(char) * (len + 1))))
		exit(EXIT_FAILURE);
	i = -1;
	while (wstr[++i])
		casted1byte[i] = (char)wstr[i];
	casted1byte[i] = '\0';
	return (casted1byte);
}
