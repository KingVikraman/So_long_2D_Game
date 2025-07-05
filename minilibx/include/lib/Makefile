#==============================================
# CONSTANT
#==============================================

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
GREEN = \033[1;32m
RESET = \033[0m

#==============================================
# DECLARATION
#==============================================

NAME = libft.a
GNL_DIR = get_next_line/
GNL = get_next_line.a

PRINTF_DIR = ft_printf/
PRINTF = ft_printf.a

#==============================================
# FILES
#==============================================

SRC = $(wildcard */*.c)
OBJS = $(SRC:.c=.o)

#==============================================
# BUILD
#==============================================

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: lib $(NAME)

$(NAME): $(GNL) $(PRINTF) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ar -q $(NAME) $(GNL_DIR)*.o
	@ar -q $(NAME) $(PRINTF_DIR)*.o
	@echo "$(GREEN)libft compiled$(RESET)"

lib:
	@make -C $(GNL_DIR)
	@make -C $(PRINTF_DIR)

clean:
	@$(RM) $(OBJS)
	@make -C $(GNL_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@$(RM) $(NAME) $(GNL) $(PRINTF)
	@make -C $(GNL_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re lib