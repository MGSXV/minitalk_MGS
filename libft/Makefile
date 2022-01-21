FLAGS := -Wall -Wextra -Werror
NAME := libft.a
SRC_M := ft_isdigit.c ft_atoi.c

OBJ_M := $(SRC_M:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ_M) libft.h
	@ar -rcs ${NAME} ${OBJ_M}

%.o: %.c
	@$(CC) $(FLAGS) -c $^

clean:
	@rm -rf $(OBJ_M)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
