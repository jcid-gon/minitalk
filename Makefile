NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SERVER_MAIN = srcs/server.c
CLIENT_MAIN = srcs/client.c

SERVER_BONUS = bonus/server_bonus.c
CLIENT_BONUS = bonus/client_bonus.c

OBJS_SERVER_BONUS = $(SERVER_BONUS:.c=.o)
OBJS_SERVER_MAIN = $(SERVER_MAIN:.c=.o)
OBJS_CLIENT_BONUS = $(CLIENT_BONUS:.c=.o)
OBJS_CLIENT_MAIN = $(CLIENT_MAIN:.c=.o)
CC = clang
CCFLAGS = -Wall -Werror -Wextra
RM = rm -rf
PRINTF_PATH = ./ft_printf/
LIBFT_PATH = ./libft/

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME_CLIENT): $(OBJS_CLIENT_MAIN) $(OBJS_SERVER_MAIN)
	$(MAKE) -C $(PRINTF_PATH)
	mv ./ft_printf/libftprintf.a .
	$(MAKE) -C $(LIBFT_PATH)
	mv ./libft/libft.a .
	$(CC) $(CCFLAGS) $(OBJS_CLIENT_MAIN) -L . -lftprintf -lft -o $(NAME_CLIENT)
	$(CC) $(CCFLAGS) $(OBJS_SERVER_MAIN) -L . -lftprintf -lft -o $(NAME_SERVER) 
	
all: $(NAME_CLIENT)

bonus: $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	$(MAKE) -C $(PRINTF_PATH)
	mv ./ft_printf/libftprintf.a .
	$(MAKE) -C $(LIBFT_PATH)
	mv ./libft/libft.a .
	$(CC) $(CCFLAGS) $(OBJS_CLIENT_BONUS) -L . -lftprintf -lft -o $(NAME_CLIENT_BONUS)
	$(CC) $(CCFLAGS) $(OBJS_SERVER_BONUS) -L . -lftprintf -lft -o $(NAME_SERVER_BONUS) 

clean:
	$(MAKE) -C $(PRINTF_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS_SERVER_BONUS)
	$(RM) $(OBJS_SERVER_MAIN)
	$(RM) $(OBJS_CLIENT_BONUS)
	$(RM) $(OBJS_CLIENT_MAIN)


fclean: clean
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER_BONUS)
	$(RM) $(NAME_CLIENT_BONUS)
	$(RM) libftprintf.a
	$(RM) libft.a

re: fclean all

.PHONY: all clean fclean re
