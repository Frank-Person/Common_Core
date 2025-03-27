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
SRCS = 
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I .

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "Executable created!"

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
