# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnichola <nic.flenghi@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 21:47:42 by fnichola          #+#    #+#              #
#    Updated: 2021/04/17 07:53:16 by fnichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = test.out

LIBFT_DIR = ../00-libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(LIBFT_DIR)

libft:
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -g -o $(NAME) -I$(LIBFT_DIR)

test: $(NAME)
	./$(NAME)

clean:
	$(RM) -r $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
