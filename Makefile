NAME_CLIENT = client

NAME_SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM	= rm -rf

all	: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : client.c minitalk.h
		$(CC) $(CFLAGS) client.c utils.c -o client

$(NAME_SERVER) : server.c minitalk.h
		$(CC) $(CFLAGS) server.c utils.c -o server

bonus	: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS)	: client_bonus.c minitalk.h
		$(CC) $(CFLAGS) client_bonus.c utils.c -o client_bonus

$(SERVER_BONUS)	: server_bonus.c minitalk.h
		$(CC) $(CFLAGS) server_bonus.c utils.c -o server_bonus
clean	:
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

fclean	:
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
		
re	:    fclean all

.PHONY : clean fclean