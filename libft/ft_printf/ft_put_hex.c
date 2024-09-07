/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:36:13 by analunga          #+#    #+#             */
/*   Updated: 2024/07/03 17:36:23 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_base(unsigned int n, const char *base, int base_len)
{
	char			*str;
	int				len;
	unsigned int	temp;

	len = 1;
	temp = n;
	while (temp / base_len != 0)
	{
		temp /= base_len;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

int	ft_put_hex_lowercase(unsigned int n)
{
	static const char	base_hex[] = "0123456789abcdef";
	int					ret;
	char				*str;

	str = ft_itoa_base(n, base_hex, 16);
	if (!str)
		return (-1);
	ret = write(1, str, ft_strlen(str));
	free(str);
	if (ret < 0)
		return (-1);
	return (ret);
}

int	ft_put_hex_uppercase(unsigned int n)
{
	static const char	base_hex_upper[] = "0123456789ABCDEF";
	int					ret;
	char				*str;

	str = ft_itoa_base(n, base_hex_upper, 16);
	if (!str)
		return (-1);
	ret = write(1, str, ft_strlen(str));
	free(str);
	if (ret < 0)
		return (-1);
	return (ret);
}
