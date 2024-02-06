NAME = libft.a

FILES = get_next_line\
		get_next_line_utils\
		ft_split\
		ft_atoi\
		ft_strlen \
		ft_substr \
		ft_strncmp \
		ft_split

SRC = $(foreach f, $(FILES), $(f).c)
OBJ = $(SRC:.c=.o)

FLAGS = -I../headers -Werror -Wextra -Wall -g3

all: $(NAME)
r: re
	./$(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

.c.o:
	@gcc $(FLAGS) -o $@ -c $<

$(LIB):
	@make -C libft
	@cp libft/libft.a ./

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re