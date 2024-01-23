NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = pipex pipex_utils
OFILES = $(SRCS:%=%.o)

all: $(NAME)

$(NAME): makelibft $(OFILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(OFILES) -L$(LIBFTDIR) -lft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

makelibft:
	@make -C $(LIBFTDIR)

clean:
	@rm -f $(OFILES)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re makelibft
