/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:14:13 by zwode             #+#    #+#             */
/*   Updated: 2019/09/06 15:07:20 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		for_base(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * for_base(nb, pow - 1));
}

void	flag_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (for_base(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	ft_putstr(nbr);
}

void	flag_u(unsigned int num)
{
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}

int		ft_nbrlen(long long num)
{
	int i;

	i = 0;
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	i++;
	return (i);
}

int		flag_ld(long long num)
{
	long long i[2];

	i[0] = 0;
	if (num == (-922337203685477580.8 * 10))
	{
		ft_putstr("-9223372036854775808");
		return (0);
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	while (num > 0)
	{
		i[0] = num % 10 + (i[0] * 10);
		num /= 10;
	}
	i[1] = ft_nbrlen(i[0]);
	while (i[1] > 0)
	{
		ft_putchar((i[0] % 10) + '0');
		i[0] /= 10;
		i[1]--;
	}
	return (1);
}