/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:15:58 by adouay            #+#    #+#             */
/*   Updated: 2022/05/18 17:11:49 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	while (n >= 10)
	{
		ft_print_int(n / 10);
		n = n % 10;
	}
	ft_printchar(n + 48);
}

void	ft_print_uint(unsigned int n)
{
	while (n >= 10)
	{
		ft_print_int(n / 10);
		n = n % 10;
	}
	ft_printchar(n + 48);
}

int	ft_len_int(long long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_int(int n)
{
	ft_print_int(n);
	return (ft_len_int(n));
}

int	ft_uint(unsigned int n)
{
	ft_print_uint(n);
	return (ft_len_int(n));
}
