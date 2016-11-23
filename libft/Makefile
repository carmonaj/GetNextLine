# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/23 20:51:57 by jcarmona          #+#    #+#              #
#    Updated: 2016/11/22 23:33:01 by jcarmona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC	 	= gcc

CFLAGS 	= -Wall -Wextra -Werror


FILES 	= ft_putchar.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strcat.c  \
		  ft_strncat.c ft_strcpy.c ft_strncpy.c ft_atoi.c ft_tolower.c   \
		  ft_toupper.c ft_isalpha.c ft_isdigit.c ft_isascii.c 			 \
		  ft_memcpy.c ft_isprint.c ft_bzero.c ft_isalnum.c 	ft_strnew.c  \
		  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strchr.c 	 \
		  ft_strstr.c ft_strnstr.c ft_strrchr.c ft_putstr.c 			 \
		  ft_putendl.c ft_memalloc.c ft_strclr.c ft_striter.c			 \
		  ft_striteri.c ft_strmap.c ft_putnbr.c ft_strmapi.c ft_strequ.c \
		  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c			 \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_memdel.c	 \
		  ft_strdel.c ft_strsplit.c ft_itoa.c ft_memmove.c ft_memset.c	 \
		  ft_strlcat.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd.c			 \
		  ft_lstiter.c ft_lstmap.c ft_lstdelone.c ft_lstdel.c			 \
		  ft_isupper.c ft_find_next_prime.c ft_is_prime.c ft_sqrt.c		 \
		  ft_swap.c ft_digitlen.c

OBJS 	= $(FILES:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -I includes/ -c $(FILES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


