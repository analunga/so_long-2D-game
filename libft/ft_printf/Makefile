# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analunga <analunga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 17:41:20 by analunga          #+#    #+#              #
#    Updated: 2024/07/03 17:41:24 by analunga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= 		gcc
CFLAGS	= 		-Wall -Wextra -Werror 
SOURCE 	=		ft_absolute_value.c ft_print_address.c ft_printchar.c ft_printf.c \
				ft_put_base.c ft_put_hex.c ft_put_str.c ft_putchar.c ft_putint.c \
				ft_putnbr.c ft_putunsigned.c ft_strchr.c ft_strlen.c ft_handlers.c
OBJS	= 		$(SOURCE:.c=.o)

NAME	=		libftprintf.a

all: 			$(NAME)

$(NAME): 		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
			
clean:
				@rm -f $(OBJS)

fclean: clean
				@rm -f $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re
