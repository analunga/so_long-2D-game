/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:38:07 by analunga          #+#    #+#             */
/*   Updated: 2024/07/03 17:38:18 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_fd(const char *str, int fd)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (write(fd, str, 1) == -1)
			return (-1);
		count++;
		str++;
	}
	return (count);
}

static int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	int				count;

	count = 0;
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		un = -n;
		count++;
	}
	else
		un = n;
	if (un >= 10)
	{
		if (ft_putnbr_fd(un / 10, fd) == -1)
			return (-1);
	}
	if (write(fd, &"0123456789"[un % 10], 1) == -1)
		return (-1);
	return (count + 1);
}

static int	ft_intlen(int n)
{
	int	length;

	length = 0;
	if (n < 0)
		length++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int	ft_putint(int n)
{
	int	int_length;

	if (n == -2147483648)
	{
		if (ft_putstr_fd("-2147483648", 1) == -1)
			return (-1);
		int_length = 11;
	}
	else
	{
		int_length = ft_intlen(n);
		if (ft_putnbr_fd(n, 1) == -1)
			return (-1);
	}
	return (int_length);
}
