# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 21:20:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/18 04:01:38 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lbmp.a
CC = clang
SRC = lbmp_load.c lbmp_int_read.c lbmp_get_info.c lbmp_destroy.c
OBJS = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) lbmp_test.c $(NAME) -o test

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean $(NAME)
