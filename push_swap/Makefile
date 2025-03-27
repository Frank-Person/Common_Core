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
SRCS = push_swap.c src/algorithms/greedy_sort.c src/algorithms/small_cases.c src/lst_utils/lst_utils_1.c src/lst_utils/lst_utils_2.c src/stack_utils/indexation.c src/stack_utils/make_stack.c src/stack_utils/operations.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I .

all: $(NAME)
	@echo "Executable created!"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	@if ls *.o >/dev/null 2>&1; then \
		rm -f $(OBJS); \
		echo "Object files deleted!"; \
	else \
		echo "No object files to delete!"; \
	fi


fclean: clean
	@rm -f $(NAME)
	@echo "Executable deleted!"

re: fclean all
	@echo "Remaking executable..."

