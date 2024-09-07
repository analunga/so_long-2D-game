/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:34:05 by analunga          #+#    #+#             */
/*   Updated: 2024/07/03 17:34:17 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_unsigned(va_list args)
{
	return (ft_putunsigned(va_arg(args, unsigned int)));
}

static int	handle_percent(void)
{
	return (ft_putchar('%'));
}

static int	handle_unknown(const char format)
{
	ft_putchar('%');
	ft_putchar(format);
	return (-1);
}

static int	ft_handle_format(va_list args, const char format)
{
	if (format == 'c')
		return (handle_char(args));
	if (format == 's')
		return (handle_string(args));
	if (format == 'd' || format == 'i')
		return (handle_int(args));
	if (format == 'X')
		return (handle_hex(args, 1));
	else if (format == 'x')
		return (handle_hex(args, 0));
	if (format == 'p')
		return (handle_pointer(args));
	if (format == 'u')
		return (handle_unsigned(args));
	if (format == '%')
		return (handle_percent());
	return (handle_unknown(format));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;
	int		result;

	printed_chars = 0;
	va_start(args, format);
	while (*format)
	{
		result = 0;
		if (*format == '%')
		{
			format++;
			result = ft_handle_format(args, *format);
		}
		else
			result = ft_printchar(*format, 1);
		if (result == -1)
		{
			return (-1);
		}
		printed_chars += result;
		format++;
	}
	va_end(args);
	return (printed_chars);
}
