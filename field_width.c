/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:32:30 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/03 13:24:22 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*field_width(char *str, fstr_t *ptrfstring)
{
	int len;
	int fwidth;
	char *newstr;
	char paddchar;

	len = ft_strlen(str);
	fwidth = ft_atoi(ptrfstring->fwidthvalue);
	if (fwidth > len)
	{
		newstr = ft_strnew(fwidth);
		if (ptrfstring->flags[1])
			paddchar = '0';
		else
			paddchar = ' ';
		ft_memset(newstr, paddchar, fwidth - len);
		ft_strcat(newstr, str);
	}
	return (newstr);
}
