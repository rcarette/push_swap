/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:46:18 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/05 09:42:53 by rcarette         ###   ########.fr       */
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
	char			time_opt;
	char			last_instruction;

}					t_opt;

typedef struct		s_rotate
{
	int				rotate_top;
	int				rotate_bottom;
	int				double_rotate;
	int				conduct;

}					t_rotate;


int					get_arguments(const char **av, t_push **list, t_opt *opt);
void				ft_exit(t_push **push);
int					is_sorted(t_push *list_a);
int					is_sorted_desc(t_push *list);
int					ft_get_mediane(t_push *list, int choice);
int					ft_getlast_elem(t_push *list_a);
int					ft_getbig_value(t_push *list);
t_push				*ft_getdata_position(t_push *list, int data);

void				ft_start_ascending(t_push **list_a, t_push **list_b);
void				ft_start_descending(t_push **list_a, t_push **list_b);
void				ft_resolve_ascending(t_push **list_a, t_push **list_b, \
																	int choice);
void				ft_tree_elements_ascending(t_push **list_a, \
															t_push **list_b);
void				ft_five_elements_ascending(t_push **list_a, t_push **list_b);
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
int			ft_getsmall_position(t_push *list_a);
int			ft_getsmall_value(t_push *list);
int			ft_getbig_position(t_push *list_a);
t_push		*dupliq(t_push *list);
void		init_opt(t_opt *opt);
void		ft_usage(t_push **list_a);
void		check_option(t_opt *opt);
void		visualization(t_push *list_a, t_push *list_b, t_opt *opt);
#endif
