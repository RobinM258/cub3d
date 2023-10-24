NAME = cub3d

LIB = libft.a

FILES = main \
		init_texture \
		mlx_key_hook

SRC = $(foreach f, $(FILES), srcs/$(f).c)
OBJ = $(SRC:.c=.o)

FS = -fsanitize=address -g

CFLAGS = -Iheaders -Wextra -Wall -IMLX42/include

GFLAGS = -Iheaders $(LIB) -Werror -Wextra -Wall MLX42/build/libmlx42.a -IMLX42/include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -lm

all: $(NAME)
r: re
	./$(NAME)
$(NAME): $(LIB) $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(GFLAGS) -fsanitize=address -g

.c.o:
	@gcc $(CFLAGS) -o $@ -c $< -g

$(LIB):
	@make -C libft
	@cp libft/libft.a ./

clean:
	@make -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME) $(LIB)

re: fclean all

.PHONY: all bonus clean fclean re