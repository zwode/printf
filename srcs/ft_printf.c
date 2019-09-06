/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:24:11 by bglover           #+#    #+#             */
/*   Updated: 2019/09/06 20:20:40 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"	

void		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr(va_arg(ap, int));
			else if (format[i] == 'o')
				flag_base(va_arg(ap, int), 8);
			else if (format[i] == 'c')
				ft_putchar(va_arg(ap, int));
			else if (format[i] == 's')
				ft_putstr(va_arg(ap, char *));
			else if (format[i] == 'x')
				flag_base(va_arg(ap, int), 16);
			else if (format[i] == 'u')
				flag_u(va_arg(ap, unsigned int));
			else if (format[i] == 'l' && format[++i] == 'd')
				flag_ld(va_arg(ap, long long));
			else if (format[i] == '%')
				write(1, &format[i], 1);
			i++;
		}
		else
			write(1, &format[i++], 1);
}
