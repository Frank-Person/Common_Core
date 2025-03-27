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
SRCS1 =
SRCS2 =
OBJS1 = $(SRCS1:%.c=%.o)
OBJS2 = $(SRCS2:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I .

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJS1)
	@$(CC) $(OBJS1) -o $(EXEC1)
	@echo "Client created!"

$(EXEC2): $(OBJS2)
	@$(CC) $(OBJS2) -o $(EXEC2)
	@echo "Server created!"

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	@if ls *.o >/dev/null 2>&1; then \
		rm -f $(OBJS1) $(OBJS2); \
		echo "Object files deleted!"; \
	else \
		echo "No object files to delete!"; \
	fi

fclean: clean
	@rm -f $(EXEC1) $(EXEC2)
	@echo "Executables deleted!"

re: fclean all
	@echo "Remaking executables..."
