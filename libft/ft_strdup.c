/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:41:47 by gofernan          #+#    #+#             */
/*   Updated: 2017/11/17 20:42:12 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;
	int		count;

	c = NULL;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	c = (char *)malloc((count + 1) * sizeof(char));
	if (c == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
