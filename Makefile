CC=cc

FLAGS=-Wall -Werror -Wextra

LIBFT =libft.a

all: server client $(LIBFT)

server: server.o $(LIBFT)
	@$(CC) $(FLAGS) -o server server.o -L. $(LIBFT)
	@echo "...server linked."

server.o: server.c $(LIBFT)
	@$(CC) $(FLAGS) -c server.c -o server.o
	@echo "...server compiled."

client: client.o $(LIBFT)
	@$(CC) $(FLAGS) -o  client client.o -L. $(LIBFT)
	@echo "...client linked."

client.o: client.c
	@$(CC) $(FLAGS) -c client.c -o client.o
	@echo "...client compiled."

$(LIBFT): libft/$(LIBFT)
	@cp libft/$(LIBFT) $(LIBFT)
	@echo "...libft.a copied to current directory."

libft/$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf client.o server.o
	@echo "...server and client OBJS cleaned."
	@rm -rf server client
	@echo "...server and client cleaned."

fclean:clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(LIBFT)
	@echo "...libft.a cleaned."

re: fclean all

.PHONY: all clean fclean re