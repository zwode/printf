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

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t_list_1;

	t_list_1 = (t_list *)malloc(sizeof(t_list));
	if (!t_list_1)
		return (NULL);
	if (!content)
	{
		t_list_1->content = (void *)content;
		t_list_1->content_size = 0;
		t_list_1->next = NULL;
		return (t_list_1);
	}
	t_list_1->content = malloc(content_size);
	if (!(t_list_1->content))
	{
		free(t_list_1);
		return (NULL);
	}
	ft_memcpy(t_list_1->content, content, content_size);
	t_list_1->content_size = content_size;
	t_list_1->next = NULL;
	return (t_list_1);
}
