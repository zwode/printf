/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:12:02 by zwode             #+#    #+#             */
/*   Updated: 2019/09/30 13:52:57 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../include/libft/libft.h"
# define FLAGS "cspdiouxXegfC%SbEGF"

void	flag_base(int value, int base);
int		ft_printf(const char *restrict form, ...);
int		flag_u(unsigned num);
int		flag_ld(long long num);
int		flag_llu(unsigned long long num);
void	cheak_point(const char *form, int i);
int		ft_atoi_finder(const char *str, int sym);
int		ft_print_float(long double db, int acc);
int		cheaker_point(int num, const char *form, int i, va_list ap);

#endif
