NAME = libft.a

FILES = ft_strlen \
		ft_freetab \
		ft_printab \
		ft_strjoin \
		ft_itoa \
		gnl \
		gnl_utils

S = $(foreach f, $(FILES), $(f).c)
OBJ = $(S:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I../headers

all: $(NAME)

$(NAME): $(OBJ)
	@printf ">  \x1b[32mAll libft object compiled\x1b[0m\n"
	@ar -rc $(NAME) $(OBJ)
	@printf ">  \x1b[32m$(NAME) compiled \x1b[0m\n"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@printf ">  \x1b[31m$(NAME) deleted\x1b[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re