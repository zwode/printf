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

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst)
		return ;
	if (!del)
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst)->content = NULL;
		*alst = (*alst)->next;
	}
}
