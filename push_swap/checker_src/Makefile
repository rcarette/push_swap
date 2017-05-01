# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:16:43 by rcarette          #+#    #+#              #
#    Updated: 2017/04/28 15:51:07 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
FLAGS = -Wall -Wextra -Werror -fsanitize=address
CC = clang $(FLAGS)
INC = ../inc/
LIBFT = ../libft/
INC_LIB = ../libft/
ALL_INC = -I $(INC) -I $(INC_LIB)
SRCS = checker.c\
	   ../ps_src/get_arguments.c\
	   ../ps_src/ft_exit.c\
	   ../instruction/ft_reverse_rotate.c\
	   ../instruction/ft_rotate.c\
	   ../instruction/push.c\
	   ../instruction/swap_pile.c\
	   is_sorted.c\

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(ALL_INC) -L $(LIBFT) -lft

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all