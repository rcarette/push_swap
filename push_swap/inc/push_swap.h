/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:46:18 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 18:03:59 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# define DEFAULT "\033[0;0m"
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"

typedef struct		s_opt
{
	char			desc;
	char			instruc;
	char			time;
	char			visualization;
	int				time_opt;
	char			last_instruction;

}					t_opt;

typedef struct		s_rotate
{
	int				rotate_a;
	int				rotate_b;
	int				double_rotate;
	int				value_a;
	int				value_b;
	int				status;

}					t_rotate;


int					get_arguments(const char **av, t_push **list, t_opt *opt);
void				ft_exit(t_push **push);
void				ft_start_ascending(t_push **list_a, t_push **list_b,\
																t_opt *opt);
void				ft_resolve_ascending(t_push **list_a, t_push **list_b,\
																t_opt *opt);
void				swap_pile(t_push **pile);
void				swap_ss(t_push **pile_a, t_push **pile_b);
void				push(t_push **list_a, t_push **list_b, int choice);
void				ft_rotate(t_push **list_a, t_push **list_b, int choice);
void				ft_rotate_rr(t_push **list_a, t_push **list_b);
void				ft_reverse_rotate(t_push **list_a, t_push **list_b, \
																int choice);
void				ft_reverse_rotate_rrr(t_push **list_a, t_push **list_b);

void				init_opt(t_opt *opt);
void				ft_usage(t_push **list_a);
void				check_option(t_opt *opt);
void				visualization(t_push *list_a, t_push *list_b, t_opt *opt);
void				init_select_rotate(t_rotate *rotate);
int					ft_getbig_value(t_push *list);
int					ft_getposition_big_value(t_push *list, int data);

void				select_bestshot(t_push *list_a, t_push *list_b, \
														t_rotate *best_shot);
void				init_rotate(t_push **list);
t_push				*ft_getdata(t_push *list_b, int position);
int					ft_getposition(t_push *list_b, int value);
void				replace_big_value(t_push **list_b, t_push **list_a,\
																t_opt *opt);
void				check_if_sorted(t_push **list_a, t_opt *opt, int i_coups,\
															t_push *list_b);
void				messag(char *str, int choice, long long nbr_coup, \
																t_opt *opt);
void				ft_exit_checker(t_push **list_a, t_push **list_b);
int					check_data_list(t_push *list, int data);
int					check_data(const char *str);
void				ft_tree_elements_descending(t_push **list_a, \
															t_push **list_b);
void				ft_five_elements_descending(t_push **list_a, \
														t_push **list_b);
#endif
