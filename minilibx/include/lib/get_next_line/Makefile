NAME = ../get_next_line.a

SRC = 	get_next_line.c \
		get_next_line_utils.c
	  
OBJS = $(SRC:.c=.o)

CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror

GREEN = \033[1;32m
RESET = \033[0m

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)get_next_line compiled$(RESET)"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
