/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:52:30 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/20 02:22:29 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *naz, ...);
int		ft_putnbr_fd(int n);
int		ft_putchar_fd(char c);
int		ft_putstr_fd(char *s);
int		ft_lowhex(unsigned int num);
int		ft_uphex(unsigned int num);
int		ft_putnbr_u(unsigned int n);
int		ft_print_p(unsigned long long p);
int		ft_hex(unsigned long long num);

#endif
