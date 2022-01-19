# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 17:39:56 by sel-kham          #+#    #+#              #
#    Updated: 2021/12/15 01:24:26 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS := -Wall -Wextra -Werror

HEADER := ft_printf.h

NAME := libftprintf.a

OBJ_DIR := Object_Files

SRC_FILES_M := ft_printf.c\
			ft_printf_utils.c\
			ft_putnbr_base.c\
			ft_putchar.c\
			ft_putstr.c\
			
OBJ_FILES_M := $(addprefix $(OBJ_DIR)/, $(SRC_FILES_M:.c=.o))

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJ_FILES_M) $(HEADER)
	ar -rcs $(NAME) $(OBJ_FILES_M)

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all