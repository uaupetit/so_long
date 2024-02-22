/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:49:44 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:02:16 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type(va_list ap, int i)
{
	int	nbchar;

	nbchar = 0;
	if (i == 'c')
		nbchar += ft_putchar_fd(va_arg(ap, int), 1);
	else if (i == '%')
		nbchar += ft_putchar_fd('%', 1);
	else if (i == 's')
		nbchar += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (i == 'd' || i == 'i')
		nbchar += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (i == 'p')
		nbchar += ft_ptr_fd(va_arg(ap, unsigned long long), 1, 'p');
	else if (i == 'u')
		nbchar += ft_putnbr_unsigned_fd(va_arg(ap, unsigned int), 1);
	else if (i == 'x')
		nbchar += ft_putnbr_base_fd(va_arg(ap, unsigned int), 1, 'x');
	else if (i == 'X')
		nbchar += ft_putnbr_base_fd(va_arg(ap, unsigned int), 1, 'X');
	return (nbchar);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		nbchar;
	va_list	ap;

	i = 0;
	nbchar = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			nbchar++;
		}
		else
		{
			nbchar += ft_type(ap, format[i + 1]);
			i += 2;
		}
	}	
	va_end(ap);
	return (nbchar);
}
/*
#include <stdio.h>

int	main()
{
	char s[] = "ABC";
//	char c = 'a';
//	int chiffre = 2;
//	int nb = 4561;

	printf("char s =  %p\n", s);
	ft_printf("char s =  %p\n", s);

	if (ac > 1)
	{
	int nbchar = ft_printf("dans la string %s, il y'a le char %c\n", s, c);
	printf("nbchar = %d\n", nbchar);
	printf("dans la string %s, il y'a le char %c\n", s, c);
	ft_printf = ft_printf("dans la string %s, il y'a le char %c/n", s, c);
	printf = printf("dans la string %s, il y'a le char %c/n", s, c);
	
	ft_printf("ma fonction : \nnb x : %x, nb X : %X  \n", nb, nb);
	printf("vrai fct : \nnb x : %x, nb X : %X \n", nb, nb);
	
	ft_printf("dans le nb %u, il y'a le chiffre  %u/n", nombre, chiffre);
	printf("dans le nb %u, il y'a le chiffre  %u/n", nombre, chiffre);
		
	}
	
}
*/
