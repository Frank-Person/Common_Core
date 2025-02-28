# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 17:47:13 by mrapp-he          #+#    #+#              #
#    Updated: 2025/02/28 18:31:34 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SRCS = push_swap.c operations.c lst_utils_1.c lst_utils_2.c handle_args.c
OBJS := $(SRC:%.c=%.o)
CC = cc
CCFLGS = -Wall -Wextra -Werror
CPPFLGS = -I .

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CPPFLGS) $(CCFLGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all
