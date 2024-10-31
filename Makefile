# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 16:27:18 by mrapp-he          #+#    #+#              #
#    Updated: 2024/10/31 17:14:42 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLD = libft.h
SRC = $(wildcard *.c) #Delete wildcard
OBJ := $(SRC:%.c=%.o)
CC = cc -Wall -Wextra -Werror
CPPFLGS = -I $(INCLD)

all: $(NAME) test #Delete test

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CPPFLGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean #Delete "rm -f test"
	@rm -f $(NAME)
	@rm -f test 

re: fclean all

test: #Delete this rule
	@$(CC) -lbsd main.c $(NAME) -o test
	@./test