CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_S = server.c

SRC_C = client.c

OBJ_S = $(SRC_S:%.c=%.o)

OBJ_C = $(SRC_C:%.c=%.o)

HEADER = minitalk.h

all : server client

server: $(OBJ_S) libft $(HEADER)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ_S) -Llibft -lft -o server

client: $(OBJ_C) libft $(HEADER)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ_C) -Llibft -lft -o client

libft:
	@make -C libft

clean:
	@make clean -C libft
	@rm -rf $(OBJ_S) $(OBJ_C)
	@echo "...objs removed."

fclean:	clean
	@make fclean -C libft
	@rm -rf server client
	@echo "...binaries removed."

re:	fclean all

.PHONY:	all clean fclean re