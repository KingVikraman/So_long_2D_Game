NAME = ../ft_printf.a

SRC = 	ft_printf.c ft_strlen.c \
		putchr.c putstr.c \
		putnbr.c put_uint.c puthex.c\
		putptr.c
	  
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
	@echo "$(GREEN)ft_printf compiled$(RESET)"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
