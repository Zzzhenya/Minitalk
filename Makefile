NAME1 = server

NAME2 = client

LIBFT = libft.a

HEADER = minitalk.h

SRCS = server.c 

SRC = client.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(SRCS) $(HEADER)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME1)

$(NAME2): $(LIBFT) $(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME2)

$(LIBFT):libft/$(LIBFT)
	@cp libft/$(LIBFT) $(LIBFT)

libft/$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(LIBFT)
	@echo "...libft.a cleaned."
	@rm -f $(NAME1) $(NAME2)
	@echo "...binaries cleaned."

re: fclean all

.PHONY: all fclean re clean
