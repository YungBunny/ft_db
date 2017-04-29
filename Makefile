# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 01:09:04 by cfu               #+#    #+#              #
#    Updated: 2017/04/28 12:26:15 by cfu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_db

SRC = create.c delete.c helpers.c modify.c modify_helpers.c choices.c main.c

OBJS = $(SRC:.c=.o)

HEADER = ./includes/

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@gcc -Wall -Wextra -Werror $(OBJS) -o $(NAME)
	@./$(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
