# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 13:56:44 by jcarmona          #+#    #+#              #
#    Updated: 2016/11/16 10:55:28 by jcarmona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  	= get_next_line

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

SRCS	= get_next_line.c

OBJS 	= $(SRCS:.c=.o)


.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) -I . -L . -lft $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
