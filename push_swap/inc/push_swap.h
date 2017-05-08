/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:46:18 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/07 23:58:20 by rcarette         ###   ########.fr       */
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
	char			descending;
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
void				ft_start_ascending(t_push **list_a, t_push **list_b);
void				ft_resolve_ascending(t_push **list_a, t_push **list_b);
/*
 * INSTRUCTION
 */

/*
 * sa - sb
*/
void			swap_pile(t_push **pile);
/*
 * ss sa && sb
 */
void			swap_ss(t_push **pile_a, t_push **pile_b);
void			push(t_push **list_a, t_push **list_b, int choice);
void			ft_rotate(t_push **list_a, t_push **list_b, int choice);
void			ft_rotate_rr(t_push **list_a, t_push **list_b);
void			ft_reverse_rotate(t_push **list_a, t_push **list_b, int choice);
void			ft_reverse_rotate_rrr(t_push **list_a, t_push **list_b);

/*
 * TOOLS
 */
void		init_opt(t_opt *opt);
void		ft_usage(t_push **list_a);
void		check_option(t_opt *opt);
void		visualization(t_push *list_a, t_push *list_b, t_opt *opt);
void		init_select_rotate(t_rotate *rotate);
#endif
