/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:36:49 by analunga          #+#    #+#             */
/*   Updated: 2024/07/03 17:36:59 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	written_chars;

	written_chars = 0;
	while (*str)
	{
		if (ft_putchar(*str) == -1)
			return (-1);
		written_chars++;
		str++;
	}
	return (written_chars);
}
