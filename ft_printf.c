/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:03:39 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/20 18:22:35 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *naz, va_list tr)
{
	char	c;

	if (*naz == 'c')
	{
		c = va_arg(tr, int);
		ft_putchar_fd(c);
	}
	else if (*naz == '%')
		write(1, &*naz, 1);
	else if (*naz == 's')
		return (ft_putstr_fd(va_arg(tr, char *)));
	else if (*naz == 'x')
		return (ft_lowhex(va_arg(tr, unsigned int)));
	else if (*naz == 'X')
		return (ft_uphex(va_arg(tr, unsigned int)));
	else if (*naz == 'd' || *naz == 'i')
		return (ft_putnbr_fd(va_arg(tr, int)));
	else if (*naz == 'u')
		return (ft_putnbr_u(va_arg(tr, unsigned int)));
	else if (*naz == 'p')
		return (ft_print_p(va_arg(tr, unsigned long long)));
	else
		ft_putchar_fd(*naz);
	return (1);
}

int	ft_print(const char *naz, va_list tr, int cnt, int flag)
{
	while (*naz)
	{
		if (flag == 0)
		{
			if (*naz == '%')
			{
				flag = 1;
				cnt--;
			}
			else
				write(1, &*naz, 1);
			cnt++;
		}
		else
		{
			cnt += ft_check(naz, tr);
			flag = 0;
		}
		naz++;
	}
	return (cnt);
}

int	ft_printf(const char *naz, ...)
{
	va_list		tr;
	int			len;

	va_start(tr, naz);
	len = ft_print(naz, tr, 0, 0);
	va_end(tr);
	return (len);
}
// int main()
// {
// 	ft_printf("cspdiuxX%");
// }
