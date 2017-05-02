/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:37:24 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/02 18:13:12 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_exit_checker(t_push **list_a, t_push **list_b)
{
	(*list_a != NULL) ? clear_list(list_a) : 0;
	(*list_b != NULL) ? clear_list(list_b) : 0;
	write(1, "\033[31;1m", ft_strlen("\033[31;1m"));
	write(1, "Error\n", 6);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	exit(0);
}

static void		messag(char *str, int choice, long long nbr_coup)
{
	write(1, "Intruction(s) : (", 17);
	ft_putnbr(nbr_coup);
	write(1, ") >> ", 5);
	(choice == 1) ? write(1, str, ft_strlen(str)) : 0;
	(choice == 1) ? write(1, "OK\n", 3) : 0;
	(choice == 0) ? write(1, str, ft_strlen(str)) : 0;
	(choice == 0) ? write(1, "KO\n", 3) : 0;
	write(1, DEFAULT, ft_strlen(DEFAULT));
	write(1, "\n", 1);
}

static void		ft_start_directive(const char *directive, t_push **list_a,\
															t_push **list_b)
{
	if (!ft_strcmp(directive, "sa"))
		swap_pile(list_a, 0);
	else if (!ft_strcmp(directive, "sb"))
		swap_pile(list_b, 1);
	else if (!ft_strcmp(directive, "ss"))
		swap_ss(list_a, list_b);
	else if (!ft_strcmp(directive, "pa"))
		push(list_a, list_b, 1);
	else if (!ft_strcmp(directive, "pb"))
		push(list_a, list_b, 0);
	else if (!ft_strcmp(directive, "ra"))
		ft_rotate(list_a, list_b, 0);
	else if (!ft_strcmp(directive, "rb"))
		ft_rotate(list_a, list_b, 1);
	else if (!ft_strcmp(directive, "rr"))
		ft_rotate_rr(list_a, list_b);
	else if (!ft_strcmp(directive, "rra"))
		ft_reverse_rotate(list_a, list_b, 0);
	else if (!ft_strcmp(directive, "rrb"))
		ft_reverse_rotate(list_a, list_b, 1);
	else if (!ft_strcmp(directive, "rrr"))
		ft_reverse_rotate_rrr(list_a, list_b);
	else
		ft_exit_checker(list_a, list_b);

}

static void		ft_get_directive(t_push **list_a, t_push **list_b)
{
	char			*directive;
	long long		i_coups;

	i_coups = 0;
	directive = NULL;

	while (get_next_line(0, &directive))
	{
		ft_start_directive(directive, list_a, list_b);
		(directive != NULL) ? ft_memdel((void *)&directive) : 0;
		directive = NULL;
		++i_coups;
	}
	if (!(is_sorted(*list_a)))
		messag(GREEN, 1, i_coups);
	else
		messag(RED, 0, i_coups);
}

int				main(int argc, const char *argv[])
{
	t_push		*list_a;
	t_push		*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 1)
		if (!get_arguments(argv, &list_a))
			ft_exit(&list_a);
	if (!list_a)
		return (0);
	ft_get_directive(&list_a, &list_b);
	(list_a != NULL) ? clear_list(&list_a) : 0;
	(list_b != NULL) ? clear_list(&list_b) : 0;
	return (0);
}
