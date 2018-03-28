/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:19:07 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/05 20:29:25 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptrn;

	ptrn = (t_list *)malloc(sizeof(t_list));
	if (NULL == ptrn)
		return (NULL);
	if (NULL == content)
	{
		ptrn->content = NULL;
		ptrn->content_size = 0;
	}
	else
	{
		ptrn->content = malloc(content_size);
		if (NULL == ptrn->content)
			return (NULL);
		ft_memcpy(ptrn->content, content, content_size);
		ptrn->content_size = content_size;
	}
	ptrn->next = NULL;
	return (ptrn);
}
