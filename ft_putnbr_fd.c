/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:15:26 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/20 02:23:47 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n)
{
	int				i;
	int				b;

	i = 0;
	b = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	if (n < 0)
	{
		write (1, "-", 1);
		b++;
		n = n * (-1);
	}
	if (n >= 10)
		i = ft_putnbr_fd(n / 10);
	i++;
	ft_putchar_fd(n % 10 + '0');
	return (b + i);
}

int	ft_putnbr_u(unsigned int n)
{
	int				i;

	i = 0;
	if (n >= 10)
		i = ft_putnbr_fd(n / 10);
	i++;
	ft_putchar_fd (n % 10 + '0');
	return (i);
}
