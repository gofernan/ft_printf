/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:08:31 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/04 23:10:50 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	if (!(str = (char *)malloc((len + 1) * (sizeof(char)))))
		return (NULL);
	i = 0;
	while (*s)
	{
		str[i] = (*f)(*s);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}
