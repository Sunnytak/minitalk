# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stak <stak@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 13:54:51 by stak              #+#    #+#              #
#    Updated: 2024/05/23 16:51:37 by stak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
LIBFT = libft
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SOURCE_CLIENT = client.c
SOURCE_CLIENT_BONUS = client_bonus.c
				
SOURCE_SERVER = server.c
SOURCE_SERVER_BONUS = server_bonus.c

OBJECTS_C = $(SOURCE_CLIENT:.c=.o)
OBJECTS_S = $(SOURCE_SERVER:.c=.o)
OBJECTS_C_BONUS = $(SOURCE_CLIENT_BONUS:.c=.o)
OBJECTS_S_BONUS = $(SOURCE_SERVER_BONUS:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJECTS_C) $(LIBFT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJECTS_C) -L$(LIBFT) -lft

$(SERVER): $(OBJECTS_S) $(LIBFT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJECTS_S) -L$(LIBFT) -lft 

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJECTS_C_BONUS) $(LIBFT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(OBJECTS_C_BONUS) -L$(LIBFT) -lft

$(SERVER_BONUS): $(OBJECTS_S_BONUS) $(LIBFT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJECTS_S_BONUS) -L$(LIBFT) -lft 

CC: HCC

CFLAGS += -Wall -Wextra -Werror -g -fsanitize=address
	
clean: 
	make clean -C $(LIBFT)
	rm -f $(OBJECTS_C) $(OBJECTS_S) $(OBJECTS_C_BONUS) $(OBJECTS_S_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re