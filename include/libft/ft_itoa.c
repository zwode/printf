/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 22:47:23 by bglover           #+#    #+#             */
/*   Updated: 2019/05/10 22:47:26 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoamal(long n, unsigned long size)
{
	char *a;

	a = (char *)malloc(sizeof(char) * (size + 1));
	if (!a)
		return (NULL);
	a[size] = '\0';
	while (n)
	{
		a[--size] = '0' + n % 10;
		n /= 10;
	}
	a[--size] = '-';
	return (a);
}

static char		*ft_min_itoa(long n)
{
	size_t	i;
	long	numb;

	i = 0;
	n *= -1;
	i++;
	numb = n;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (ft_itoamal(numb, i));
}

char			*ft_itoa(int n)
{
	size_t	i;
	int		numb;
	char	*a;

	if (n < 0)
		return (ft_min_itoa(n));
	if (n == 0)
	{
		a = (char *)malloc(sizeof(char) * (2));
		if (!a)
			return (NULL);
		a[1] = '\0';
		a[0] = '0';
		return (a);
	}
	i = 0;
	numb = n;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (ft_itoamal(numb, i));
}
