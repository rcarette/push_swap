# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:04:47 by rcarette          #+#    #+#              #
#    Updated: 2017/05/08 17:03:37 by rcarette         ###   ########.fr        #
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
	   ../ps_src/ft_start_ascending.c\
	   ../ps_src/ft_resolve_ascending.c\
	   ../ps_src/replace_pile.c\
	   ../ps_src/check_data.c\
	   ../ps_src/ft_start_descending.c\

TOOLS = ../tools/init_opt.c\
		../tools/ft_usage.c\
		../tools/init_select_rotate.c\
		../tools/ft_getbig_value.c\
		../tools/ft_best_shots.c\
		../tools/get_informations.c\

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(TOOLS) $(ALL_INC) -L $(LIBFT) -lft
	mv $(NAME) ../
	

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f ../$(NAME)

re: fclean all
