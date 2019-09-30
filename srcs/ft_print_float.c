/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:41:20 by bglover           #+#    #+#             */
/*   Updated: 2019/09/25 02:55:42 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

void	make_acc(int *rez, int acc)
{
	int i;

	i = acc;
	if (rez[i] != 0 && rez[i] >= 5)
		rez[i - 1] += 1;
	if (rez[i - 1] == 10)
	{
		while (rez[--i] == 10)
		{
			rez[i - 1] += rez[i] / 10;
			rez[i] = rez[i] % 10;
		}
	}
	i = 0;
	while (i < acc)
		ft_putnbr(rez[i++]);
}

void	make_man(int man[], int por, int acc)
{
	int i;
	int j;
	int *rez;
	int *num;

	rez = ft_intstr(1100);
	if (por < 0)
		por *= -1;
	i = 63;
	while (i > 0)
		if (man[i] == 0)
			man[i--] = '\0';
		else
			break ;
	j = -1;
	while (++j <= i)
		if (man[j] != 0)
		{
			num = ft_intstr(1100);
			num[1100 - 1] = 1;
			rez = ft_long_math_summ(rez, ft_long_math_divider(num,
			ft_long_math_squad(j + por, 1100), 1100, 0), 1100);
			free(num);
		}
	make_acc(rez, acc);
}

int	make_por(int por[])
{
	int		i;
	int		j;
	int		k;
	short	digit;

	i = 14;
	j = -1;
	k = 0;
	digit = 0;
	while (i > 0)
	{
		if (por[i] == 0 || (i == 15 && por[i] == 1))
			j++;
		else if (i != 15 && por[i] == 1)
		{
			j++;
			while (k++ < j)
				por[i] *= 2;
			k = 0;
		}
		digit += por[i--];
	}
	return (digit - 16383);
}

void	find_numb(char bin_numb[], int acc)
{
	int	i;
	int	j;
	int	sign;
	int	por[15];
	int	man[64];

	i = 0;
	j = 0;
	while (i < 80)
	{
		if (i == 0)
			sign = bin_numb[i];
		else if (i < 16)
			por[j++] = bin_numb[i];
		else
		{
			if (i == 16)
				j = 0;
			man[j++] = bin_numb[i];
		}
		i++;
	}
	make_man(man, make_por(por), acc);
}

void	print_bits(size_t const size, void const *const ptr, int acc,
			int bn)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;
	char			bin_numb[80];

	b = (unsigned char*)ptr;
	i = size - 1;
	j = 7;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			bin_numb[bn++] = byte;
			j--;
		}
		i--;
	}
	find_numb(bin_numb, acc);
}

int	ft_print_float(long double db, int acc)
{
	int				a;
	union union_1	un;

	a = db;
	ft_putnbr(a);
	write(1, ".", 1);
	db -= a;
	un.i = db;
	if (acc == 0)
		acc = 6;
	print_bits(10, &un.i, acc, 0);
	return (acc);
}
