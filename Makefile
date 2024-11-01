# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 16:27:18 by mrapp-he          #+#    #+#              #
#    Updated: 2024/11/01 19:21:46 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLD = libft.h
SRC = $(wildcard *.c) #Delete wildcard
OBJ := $(SRC:%.c=%.o)
CC = cc
CCFLGS = -Wall -Wextra -Werror
CPPFLGS = -I $(INCLD)

all: $(NAME) test #Delete test

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CPPFLGS) $(CCFLGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean #Delete "rm -f test"
	@rm -f $(NAME)
	@rm -f test 

re: fclean all

test: #Delete this rule
	@$(CC) -lbsd main.c $(NAME) -o test
	@./test