# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 12:02:39 by sel-kham          #+#    #+#              #
#    Updated: 2022/02/05 02:14:14 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS := -Wall -Wextra -Werror

SERVER := server
CLIENT := client
NAME := $(SERVER) $(CLIENT)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

PRINTF_DIR := ft_printf
PRINTF := $(PRINTF_DIR)/libftprintf.a

SERVER_B := server_bonus
CLIENT_B := client_bonus

################# COLORS #################
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(SERVER_B) $(CLIENT_B)

$(SERVER): server.c $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Making $(WHITE)server file..."
	@$(CC) $(FLAGS) server.c $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): client.c $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Making $(WHITE)client file..."
	@$(CC) $(FLAGS) client.c $(LIBFT) $(PRINTF) -o $(CLIENT)

$(SERVER_B): server_bonus.c $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Making $(WHITE)server bonus file..."
	@$(CC) $(FLAGS) server_bonus.c $(LIBFT) $(PRINTF) -o $(SERVER_B)

$(CLIENT_B): client_bonus.c $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Making $(WHITE)client bonus file..."
	@$(CC) $(FLAGS) client_bonus.c $(LIBFT) $(PRINTF) -o $(CLIENT_B)

$(LIBFT): $(shell find $(LIBFT_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)libft files..."
	@$(MAKE) -C $(LIBFT_DIR)/

$(PRINTF): $(shell find $(PRINTF_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)ft_printf files..."
	@$(MAKE) -C $(PRINTF_DIR)/

clean:
	@echo "$(RED)Removing $(WHITE)Minitalk object files..."
	@rm -rf *.o
	@echo "$(RED)Removing $(WHITE)libft object files..."
	@$(MAKE) -C $(LIBFT_DIR)/ clean
	@echo "$(RED)Removing $(WHITE)ft_printf object files..."
	@$(MAKE) -C $(PRINTF_DIR)/ clean

fclean: clean
	@echo "$(RED)Removing $(WHITE)Minittalk executable files..."
	@rm -rf $(NAME) $(SERVER_B) $(CLIENT_B)
	@echo "$(RED)Removing $(WHITE)libft static library file..."
	@$(MAKE) -C $(LIBFT_DIR)/ fclean
	@echo "$(RED)Removing $(WHITE)ft_printf static library file..."
	@$(MAKE) -C $(PRINTF_DIR)/ fclean

re: fclean all