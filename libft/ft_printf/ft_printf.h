/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:34:44 by analunga          #+#    #+#             */
/*   Updated: 2024/07/03 17:35:03 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_format {
	int	uppercase;
}	t_format;

int		ft_absolute_value(int n);
int		ft_putint(int n);
int		ft_putbase_fd(int nbr, const char *base, int fd);
int		ft_putstr(char const *str);
int		ft_print_address(void *ptr);
void	ft_putnbr(int n);
int		ft_put_hex_lowercase(unsigned int n);
int		ft_put_hex_uppercase(unsigned int n);
int		ft_printchar(char c, int fd);
int		ft_putunsigned(unsigned int n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		handle_char(va_list args);
int		handle_string(va_list args);
int		handle_int(va_list args);
int		handle_hex(va_list args, int uppercase);
int		handle_pointer(va_list args);

#endif
