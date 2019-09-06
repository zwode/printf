/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:49:02 by bglover           #+#    #+#             */
/*   Updated: 2019/05/04 17:12:51 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*list;

	if (!f)
		return (NULL);
	if (!lst)
		return (NULL);
	list = f(lst);
	new_lst = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(lst);
		if (!(list->next))
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (new_lst);
}
