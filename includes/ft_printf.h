/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:42:10 by uaupetit          #+#    #+#             */
/*   Updated: 2022/12/15 13:04:45 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int				ft_putchar_fd(char c, int fd);
int				ft_putnbr_fd(int i, int fd);
int				ft_type(va_list ap, int i);
int				ft_printf(const char *format, ...);
int				ft_putstr_fd(char *s, int fd);
int				ft_ptr_fd(unsigned long long n, int fd, char c);
int				ptrlen(unsigned long long n);
unsigned int	ft_putnbr_unsigned_fd(unsigned int i, int fd);
unsigned int	ft_putnbr_base_fd(unsigned long long i, int fd, char c);

#endif
