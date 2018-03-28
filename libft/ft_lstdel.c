/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:30:14 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/05 18:52:41 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *node;
	t_list *nextnode;

	node = *alst;
	while (node)
	{
		nextnode = node->next;
		del(node->content, node->content_size);
		free(node);
		node = nextnode;
	}
	*alst = NULL;
}
