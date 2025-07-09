#==================================================
# CONSTANTS
#==================================================
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -O3 #-g3 -fsanitize=address
RM      = rm -f

#==================================================
# NAME
#==================================================
NAME    = cub3D

#==================================================
# DIRECTORIES
#==================================================
INCLUDE_DIRS = -I./include -I./include/lib -I./include/mlx
LIB_DIR = ./include/lib
MLX_DIR = ./include/mlx

#==================================================
# LIBRARIES
#==================================================
INCLUDE_LIBS = ./include/mlx/libmlx.a ./include/lib/libft.a
MLX_FLAGS = -L./include/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

#==================================================
# FILES
#==================================================
SRC = $(wildcard ./draw/*.c) \
      $(wildcard ./game/*.c) \
      $(wildcard ./init/*.c) \
      $(wildcard ./render/*.c) \
      $(wildcard ./utils/*.c) \
      $(wildcard ./parse/*.c)

OBJ = $(SRC:.c=.o)

#==================================================
# RULES
#==================================================
all: lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDE_LIBS) $(MLX_FLAGS)

mkbonus: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(INCLUDE_LIBS) $(MLX_FLAGS)

lib:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	-@$(MAKE) -C $(LIB_DIR) clean
	-@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	-@$(MAKE) -C $(LIB_DIR) fclean
	-@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re lib mkbonus
