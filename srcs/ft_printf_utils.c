/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:27:35 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:02:16 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	ft_putnbr_unsigned_fd(unsigned int i, int fd)
{
	unsigned int	nbchar;

	nbchar = 0;
	if (i <= 9)
		nbchar += ft_putchar_fd((48 + i), fd);
	else
	{
		nbchar += ft_putnbr_fd(i / 10, fd);
		nbchar += ft_putnbr_fd(i % 10, fd);
	}
	return (nbchar);
}

unsigned int	ft_putnbr_base_fd(unsigned long long i, int fd, char c)
{
	unsigned long	nbchar;
	char			*base;

	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	nbchar = 0;
	if (i >= 16)
		nbchar += ft_putnbr_base_fd(i / 16, fd, c);
	nbchar += ft_putchar_fd(base[i % 16], fd);
	return (nbchar);
}

int	ft_ptr_fd(unsigned long long n, int fd, char c)
{
	if (!n)
		return (ft_putstr_fd("(nil)", fd));
	ft_putstr_fd("0x", fd);
	ft_putnbr_base_fd(n, fd, c);
	return (ptrlen(n) + 2);
}

int	ptrlen(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
