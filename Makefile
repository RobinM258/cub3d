NAME = cub3D

MLX = MLX42/build/libmlx42.a

LIB = libft.a

FILES = main\
		window\
		hooks\
		utils\
		utils2\
		parsing\
		parsing2\
		parsing3\
		parsing4\
		parsing5\
		ft_isdigit\
		error_management\
		find_map\
		find_map2\
		raycasting


SRC = $(foreach f, $(FILES), srcs/$(f).c)
OBJ = $(SRC:.c=.o)

CFLAGS = -Iheaders -Wextra -Wall -IMLX42/include -g3

GFLAGS = -Iheaders $(LIB) -Werror -Wextra -Wall $(MLX) -IMLX42/include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -lm

all: $(NAME)
r: re
	./$(NAME) "maps/m2.cub"

$(NAME): $(MLX) $(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(GFLAGS)

.c.o: $(LIB)
	gcc $(CFLAGS) -o $@ -c $< -g3

$(LIB):
	make -C libft
	cp libft/libft.a ./

mlx: $(MLX)
$(MLX):
	$(shell ./mlx_maker.sh)

clean:
	make -C libft clean
	rm -rf $(OBJ)
	rm -rf miniJoker.dSYM

fclean: clean
	make -C libft fclean
	rm -rf $(NAME) $(LIB)

re: fclean all

.PHONY: all bonus clean fclean re