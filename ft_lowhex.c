/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:39:50 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/20 01:35:55 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowhex(unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (num > 15)
		cnt = ft_lowhex(num / 16);
			cnt++;
	ft_putchar_fd("0123456789abcdef"[num % 16]);
	return (cnt);
}

int	ft_uphex(unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (num > 15)
	cnt = ft_uphex(num / 16);
		cnt++;
	ft_putchar_fd("0123456789ABCDEF"[num % 16]);
	return (cnt);
}

int	ft_hex(unsigned long long num)
{
	int	cnt;

	cnt = 0;
	if (num > 15)
		cnt = ft_hex(num / 16);
	cnt++;
	ft_putchar_fd("0123456789abcdef"[num % 16]);
	return (cnt);
}

int	ft_print_p(unsigned long long p)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	count += ft_hex(p);
	return (count);
}
