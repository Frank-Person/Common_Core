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
OBJS1 = $(SRCS1:%.c=$(OBJ_DIR)/src/%.o)
OBJS2 = $(SRCS2:%.c=$(OBJ_DIR)/src/%.o)
PRINTF = -L lib/ft_printf -lftprintf
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I lib
RM = rm -rf

all: printf $(EXEC1) $(EXEC2)

printf:
	@make -C lib/ft_printf --no-print-directory

$(EXEC1): $(OBJS1)
	@$(CC) $(OBJS1) -o $(EXEC1) $(PRINTF) $(INCLUDE)
	@echo "Client created!"

$(EXEC2): $(OBJS2)
	@$(CC) $(OBJS2) -o $(EXEC2) $(PRINTF) $(INCLUDE)
	@echo "Server created!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src

clean:
	@if find $(OBJ_DIR) -name "*.o" | grep . >/dev/null 2>&1; then \
		make clean -C lib/ft_printf --no-print-directory; \
		find $(OBJ_DIR) -name "*.o" -delete; \
		echo "Object files deleted!"; \
	else \
		echo "No object files to delete!"; \
	fi

fclean: clean
	@make fclean -C lib/ft_printf --no-print-directory
	@$(RM) $(EXEC1) $(EXEC2) $(OBJ_DIR)
	@echo "Executables deleted!"

re: fclean all
	@echo "Remaking executables..."
