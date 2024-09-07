/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:39:33 by analunga          #+#    #+#             */
/*   Updated: 2024/07/03 17:39:43 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	temp;

	len = 1;
	temp = n;
	while (temp / 10 != 0)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	ft_putunsigned(unsigned int n)
{
	char	*str;
	int		len;
	int		ret;

	str = ft_itoa_unsigned(n);
	if (!str)
		return (-1);
	len = 0;
	while (str[len])
		len++;
	ret = write(1, str, len);
	free(str);
	if (ret == -1)
		return (-1);
	return (len);
}
