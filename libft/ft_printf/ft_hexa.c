/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:01:31 by adouay            #+#    #+#             */
/*   Updated: 2022/05/18 23:23:25 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(unsigned long long int arg)
{
	char			*base;

	base = "0123456789abcdef";
	while (arg >= 16)
	{
		ft_print_hexa(arg / 16);
		arg = arg % 16;
	}
	write(1, &(base[arg]), 1);
}

void	ft_print_maj_hexa(unsigned long long int arg)
{
	char	*base;

	base = "0123456789ABCDEF";
	while (arg >= 16)
	{
		ft_print_maj_hexa(arg / 16);
		arg = arg % 16;
	}
	write (1, &(base[arg]), 1);
}

int	ft_len_hexa(unsigned long long int arg)
{
	int	n;

	n = 0;
	if (arg == 0)
		return (1);
	while (arg != 0)
	{
		arg = arg / 16;
		n++;
	}
	return (n);
}

int	ft_hexa(unsigned int arg, char c)
{
	if (c == 'X')
		ft_print_maj_hexa(arg);
	if (c == 'x')
		ft_print_hexa(arg);
	return (ft_len_hexa(arg));
}

int	ft_print_pointer(unsigned long long int arg)
{
	int	len;

	len = 0;
	if (arg == 0)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	write (1, "0x", 2);
	len = 2;
	ft_print_hexa(arg);
	len += ft_len_hexa(arg);
	return (len);
}
