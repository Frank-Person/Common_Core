# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 16:37:40 by mrapp-he          #+#    #+#              #
#    Updated: 2025/03/27 16:38:02 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC1 = client
EXEC2 = server
SRCS1 = client.c
SRCS2 = server.c
OBJ_DIR = build
OBJS1 = $(SRCS1:%.c=$(OBJ_DIR)/%.o)
OBJS2 = $(SRCS2:%.c=$(OBJ_DIR)/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I .

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJS1)
	@$(CC) $(OBJ_DIR) -o $(EXEC1)
	@echo "Client created!"

$(EXEC2): $(OBJS2)
	@$(CC) $(OBJ_DIR) -o $(EXEC2)
	@echo "Server created!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src

clean:
	@if ls $(OBJ_DIR)/*.o >/dev/null 2>&1; then \
		rm -rf $(OBJ_DIR); \
		echo "Object files deleted!"; \
	else \
		echo "No object files to delete!"; \
	fi

fclean: clean
	@rm -f $(EXEC1) $(EXEC2)
	@echo "Executables deleted!"

re: fclean all
	@echo "Remaking executables..."
