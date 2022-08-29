/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:00:56 by adouay            #+#    #+#             */
/*   Updated: 2022/05/18 23:25:01 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int n)
{
	char	c;

	c = n;
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		n++;
	}
	return (n);
}

int	ft_format(va_list arg, char c)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = ft_printchar((int)va_arg(arg, int));
	if (c == 's')
		counter = ft_print_string((char *)va_arg(arg, char *));
	if (c == 'p')
		counter = ft_print_pointer(va_arg(arg, unsigned long long int));
	if (c == 'd' || c == 'i')
		counter = ft_int((int)va_arg(arg, int));
	if (c == 'u')
		counter = ft_uint((unsigned int)va_arg(arg, unsigned int));
	if (c == 'x' || c == 'X')
		counter = ft_hexa((unsigned int)va_arg(arg, unsigned int), c);
	if (c == '%')
		counter = ft_printchar(37);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	arg;

	va_start(arg, format);
	counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			counter += ft_format(arg, *(++format));
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}
	va_end(arg);
	return (counter);
}
/*
int	main ()
{
	const char *p;
//	char	c;
	int count;
	int count2;
	
//	c = 'w';
	count = 0;
	count2 = 0;	
	p = 0;
	count2 = ft_printf("%p\n", p);
	count = printf("%p\n", p);
	printf("     ---------------------    \n");
	printf("%d\n", count);
	printf("%d\n", count2);
	return (0);
}
*/
