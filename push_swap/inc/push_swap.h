/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:46:18 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/01 12:48:46 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# define DEFAULT "\033[0;0m"
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"


int					get_arguments(const char **av, t_push **list);
void				ft_exit(t_push **push);
int					is_sorted(t_push *list_a);
int					ft_getmediane(t_push **list);

/*
 * INSTRUCTION
 */

/*
 * sa - sb
*/
void			swap_pile(t_push **pile, int choice);
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
int		ft_getsmall_position(t_push *list_a);
int		ft_getbig_position(t_push *list_a);
int		ft_getbefore_last(t_push *list_a, int small_position);
#endif
