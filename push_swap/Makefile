# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 20:59:07 by rcarette          #+#    #+#              #
#    Updated: 2017/05/09 01:10:44 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/
PUSHSWAP = ps_src/
CHECKER = checker_src/

all: name

lib:
		make -C $(LIBFT)

name: lib
		make -C $(PUSHSWAP)
		make -C $(CHECKER)

clean:
		make clean -C $(LIBFT)
		make clean -C $(PUSHSWAP)
		make clean -C $(CHECKER)

fclean: clean
		make fclean -C $(LIBFT)
		make fclean -C $(PUSHSWAP)
		make fclean -C $(CHECKER)

