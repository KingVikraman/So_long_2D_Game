NAME 	= so_long
CC		= cc
CFLAGS	= -Wall -Werror -Wextra

# === DIRECTORIES ===

SRC_DIR 	= src
GNL_DIR 	= libft/gnl
PRINTF_DIR	= libft/ft_printf
MLX_DIR		= minilibx

# === FILES ===

SRC_FILES 		= main.c parse_map.c map_validator.c
GNL_FILES 		= get_next_line.c get_next_line_utils.c
PRINTF_FILES	= ft_printf.c ft_printf_str.c ft_printf_ptr.c \
					ft_printf_hexdec.c ft_printf_unsigned.c

# === MinilibX paths ===
MLX_DIR = ./minilibx/include/mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm -lz

# === OBJECTS ===
SRC		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
GNL		= $(addprefix $(GNL_DIR)/, $(GNL_FILES))
PRINTF	= $(addprefix $(PRINTF_DIR)/, $(PRINTF_FILES))

OBJ		= $(SRC:.c=.o) $(GNL:.c=.o) $(PRINTF:.c=.o)

# Include paths
INCLUDES = -Iincludes -I$(GNL_DIR) -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LIB) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re