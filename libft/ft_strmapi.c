/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:50:14 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/04 22:30:25 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				len;
	unsigned int	i;

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
		str[i] = (*f)(i, *s);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}
