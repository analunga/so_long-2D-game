# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #make ak
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analunga <analunga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 18:08:53 by analunga          #+#    #+#              #
#    Updated: 2024/07/26 14:50:33 by analunga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CC = gcc

OBJ_DIR = obj/
SRC_DIR = src/
GNL_DIR = get_next_line/
LIBFT_DIR = libft/
FT_PRINTF_DIR = ft_printf
LIBMLX = lib/MLX42
LIBMLX_BUILD = $(LIBMLX)/build
LIBMLX_LIB = $(LIBMLX_BUILD)/libmlx42.a

# Include paths
HEADERS = -I./include -I$(LIBMLX)/include -I$(GNL_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(SRC_DIR)

# Conditional flag
BONUS = 0

# Source files
ifeq ($(BONUS), 1)
GNL_SRC = $(wildcard $(GNL_DIR)*_bonus.c)
GNL_HDR = $(wildcard $(GNL_DIR)*_bonus.h)
else
GNL_SRC = $(wildcard $(GNL_DIR)*.c)
GNL_HDR = $(wildcard $(GNL_DIR)*.h)
endif

SRC = $(wildcard $(SRC_DIR)*.c)

# Object files
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(notdir $(SRC) $(GNL_SRC)))

LIBS = $(LIBMLX_LIB) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a

# Detect platform
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    LDFLAGS = -ldl -lglfw -pthread -lm -flto -framework Cocoa -framework OpenGL -framework IOKit
else
    LDFLAGS = -ldl -lglfw -pthread -lm -flto
    # Add library paths for Linux
    LIB_DIRS = -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
endif

# Ensure libft and ft_printf are built before the main project
all: $(OBJ_DIR) $(LIBMLX) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBMLX):
	@if [ ! -d "$(LIBMLX)" ]; then \
		mkdir -p lib && \
		cd lib && \
		git clone https://github.com/codam-coding-college/MLX42.git && \
		cd MLX42 && \
		cmake -B build && \
		cmake --build build -j4; \
	else \
		echo "MLX42 is already installed."; \
	fi

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_DIR)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF_DIR)

# Rule to compile source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(HEADERS)
	@echo "Compiling $< -> $@"

# Rule to compile source files from get_next_line directory
$(OBJ_DIR)%.o: $(GNL_DIR)%.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(HEADERS)
	@echo "Compiling $< -> $@"

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a
	@echo "Building $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LIB_DIRS) $(LDFLAGS) -o $(NAME)

bonus:
	@$(MAKE) BONUS=1

install_brew:
	@echo "Installing Homebrew..."
	@rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew && \
		git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && \
		echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc && \
		source $HOME/.zshrc && brew update

install_glfw:
	@echo "Installing GLFW..."
	brew install glfw

install: install_brew install_glfw $(LIBMLX)

clean:
	@echo "Cleaning..."
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned up project."

fclean: clean
	@echo "Full Cleaning..."
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@rm -rf $(NAME)
	@echo "Fully cleaned project."

re: fclean all

.PHONY: all clean fclean re install_brew install_glfw $(LIBMLX) bonus
