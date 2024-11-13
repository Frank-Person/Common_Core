# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 16:27:18 by mrapp-he          #+#    #+#              #
#    Updated: 2024/11/13 02:25:24 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLD = libft.h
SRC = ft_atoi.c ft_memcpy.c ft_strlcpy.c ft_bzero.c ft_memmove.c ft_strlen.c ft_calloc.c ft_memset.c ft_strmapi.c ft_isalnum.c ft_putchar_fd.c ft_strncmp.c ft_isalpha.c ft_putendl_fd.c ft_strnstr.c ft_isascii.c ft_putnbr_fd.c ft_strrchr.c ft_isdigit.c ft_putstr_fd.c ft_strtrim.c ft_isprint.c ft_strchr.c ft_substr.c ft_itoa.c ft_strdup.c ft_tolower.c ft_striteri.c ft_toupper.c ft_memchr.c ft_strjoin.c ft_memcmp.c ft_strlcat.c ft_split.c
SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c
OBJ := $(SRC:%.c=%.o)
OBJ_B := $(SRC_B:%.c=%.o)
CC = cc
CCFLGS = -Wall -Wextra -Werror
CPPFLGS = -I . #$(INCLD)

all: $(NAME) #test #Delete test

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CPPFLGS) $(CCFLGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean #Delete "rm -f test"
	@rm -f $(NAME)
#	@rm -f test 

re: fclean all

bonus: $(OBJ) $(OBJ_B)
	@ar rcs $(NAME) $(OBJ) $(OBJ_B)

#test: #Delete this rule
#	@$(CC) -lbsd main.c $(NAME) -o test
#	@./test