CC=cc

FLAGS=-Wall -Werror -Wextra

LIBFT =libft.a

all: server client 

server: server.c $(LIBFT)
	@$(CC) $(FLAGS) server.c $(LIBFT) -o server
	@echo "...server compiled."

client: client.c $(LIBFT)
	@$(CC) $(FLAGS) client.c $(LIBFT) -o client
	@echo "...client compiled."

$(LIBFT):libft/$(LIBFT)
	@cp libft/$(LIBFT) $(LIBFT)
	@echo "...libft.a copied to current directory."

libft/$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf server client
	@echo "...server and client cleaned."

fclean:clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(LIBFT)
	@echo "...libft.a cleaned."

re: fclean all

.PHONY: all clean fclean re server client