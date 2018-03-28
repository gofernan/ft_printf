/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:29:56 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/05 23:28:48 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *newlist;
	t_list *head;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	newlist = ft_lstnew(new->content, new->content_size);
	head = newlist;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		newlist->next = ft_lstnew(new->content, new->content_size);
		newlist = newlist->next;
		lst = lst->next;
	}
	return (head);
}
