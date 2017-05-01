# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:04:47 by rcarette          #+#    #+#              #
#    Updated: 2017/05/01 14:10:59 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -fsanitize=address
CC = clang $(FLAGS)
INC = ../../include
LIBFT = ../libft/
INC_LIB = ../libft/libft.h
ALL_INC = -I $(INC) -I $(INC_LIB)
SRCS = push_swap.c\
	   get_arguments.c\
	   ft_exit.c\
	   ../instruction/ft_reverse_rotate.c\
	   ../instruction/ft_rotate.c\
	   ../instruction/push.c\
	   ../instruction/swap_pile.c\
	   ../checker_src/is_sorted.c\

TOOLS = ../tools/ft_getsmall_position.c\

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(TOOLS) $(ALL_INC) -L $(LIBFT) -lft

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
