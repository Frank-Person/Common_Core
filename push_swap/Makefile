# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 17:47:13 by mrapp-he          #+#    #+#              #
#    Updated: 2025/03/10 17:16:13 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = src/push_swap.c src/algorithms/greedy_sort.c src/algorithms/small_cases.c src/lst_utils/lst_utils_1.c src/lst_utils/lst_utils_2.c src/stack_utils/indexation.c src/stack_utils/make_stack.c src/stack_utils/operations.c
OBJ_DIR = build
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I lib

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "Executable created!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src/algorithms $(OBJ_DIR)/src/lst_utils $(OBJ_DIR)/src/stack_utils
	@echo "Build directory created!"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "Build directory deleted!"; \
	else \
		echo "No build directory to delete!"; \
	fi

fclean: clean
	@rm -f $(NAME)
	@echo "Executable deleted!"

re: fclean
	@echo "Recreating build directory..."
	@echo "Remaking executables..."
	@make --no-print-directory

