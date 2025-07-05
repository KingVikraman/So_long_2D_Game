#==================================================
# CONSTANT
#==================================================

CC = gcc
FLAG = -Wall -Werror -Wextra -O3 #-g3 -fsanitize=address
RM = rm -f

#==================================================
# DECLARATION
#==================================================

NAME = cub3D
INCLUDE = ./include/mlx/libmlx.a ./include/lib/libft.a
MLX_FLAG = -L./include/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

LIB_DIR = ./include/lib
MLX_DIR = ./include/mlx

#==================================================
# FILES
#==================================================

SRC = $(wildcard ./draw/*.c) \
	$(wildcard ./game/*.c) \
	$(wildcard ./init/*.c) \
	$(wildcard ./render/*.c) \
	$(wildcard ./utils/*.c) \
	$(wildcard ./parse/*.c) \
	
OBJ = $(SRC:.c=.o)

#===================================================
# BUILD
#===================================================

all : lib $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ $(INCLUDE) $(MLX_FLAG) 

mkbonus: $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $^ $(INCLUDE) $(MLX_FLAG) 

lib:
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME) 
	make -C $(LIB_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all lib clean fclean re
