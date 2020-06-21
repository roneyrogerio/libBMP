# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 21:20:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/21 04:43:45 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lbmp.a
CC = clang
SRC = lbmp_load.c lbmp_int_read.c lbmp_destroy.c lbmp_int_offset.c \
	  lbmp_get_pixel_ptr.c lbmp_get_pixel_color.c lbmp_get_bpp.c \
	  lbmp_get_size.c lbmp_get_width.c lbmp_get_height.c \
	  lbmp_set_pixel_color.c lbmp_new.c lbmp_save.c lbmp_strerror.c \
	  lbmp_int_set_err.c
OBJS = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) lbmp_test.c $(NAME) -o test -lmlx -lXext -lX11

clean:
	rm -f $(OBJS)
	rm -f lbmp_test.o

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean $(NAME)
