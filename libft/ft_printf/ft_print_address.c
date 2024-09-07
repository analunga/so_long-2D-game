/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:32:53 by analunga          #+#    #+#             */
/*   Updated: 2024/07/03 17:33:06 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_digit(char digit)
{
	return (ft_putchar(digit));
}

static int	print_hex_address(unsigned long long address)
{
	int		written_chars;
	char	buffer[20];
	int		i;

	i = 0;
	written_chars = 0;
	while (1)
	{
		buffer[i] = "0123456789abcdef"[address % 16];
		address /= 16;
		if (address == 0)
			break ;
		i++;
	}
	while (i >= 0)
	{
		if (print_hex_digit(buffer[i]) == -1)
			return (-1);
		written_chars++;
		i--;
	}
	return (written_chars);
}

static int	print_address_prefix(void)
{
	return (ft_putstr("0x"));
}

int	ft_print_address(void *ptr)
{
	unsigned long long	address;
	int					written_chars;

	address = (unsigned long long)ptr;
	written_chars = 0;
	if (print_address_prefix() == -1)
		return (-1);
	written_chars += 2;
	written_chars += print_hex_address(address);
	return (written_chars);
}
