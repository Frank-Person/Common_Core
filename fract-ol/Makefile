# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 16:25:42 by mrapp-he          #+#    #+#              #
#    Updated: 2025/03/27 16:26:35 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = fractol.c
OBJ_DIR = build
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLX = -lmlx -lXext -lX11 -lm
INCLUDE = -I lib

all: mlx $(NAME)

mlx:
	@make -C lib/minilibx-linux --no-print-directory

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LIBMLX) $(INCLUDE)
	@echo "Executable created!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "Build directory deleted!"; \
	else \
		echo "No build directory to delete!"; \
	fi

fclean: clean
	@rm -f $(NAME)
	@make -C clean lib/minilibx-linux --no-print-directory
	@echo "Executable deleted!"

re: fclean
	@echo "Recreating build directory..."
	@echo "Remaking executables..."
	@make --no-print-directory
