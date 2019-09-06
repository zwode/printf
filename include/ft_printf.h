/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:12:02 by zwode             #+#    #+#             */
/*   Updated: 2019/09/06 15:06:46 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include "../include/libft/libft.h"

void	flag_base(int value, int base);
void	ft_printf(const char *restrict format, ...);
void	flag_u(unsigned int num);
int		flag_ld(long long num);
