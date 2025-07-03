NAME 	= so_long
CC		= cc
CFLAG	= -Wall -Werror -Wextra
SRC		= src/main.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -lXext -lX11 -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all