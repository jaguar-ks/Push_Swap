/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:50:06 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/08 05:32:34 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libtool/libft.h"

t_list	*take_stack(int ac, char **av);
void	sa(t_list *stack, char c);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **a, t_list **b, char c);
void	ra(t_list **stack, char c);
void	rr(t_list **sa, t_list **sb);
void	rra(t_list **stack, char c);
void	rrr(t_list **sa, t_list **sb);
void	sort_stack(t_list **stack_a, t_list **stack_b);
int		check_sort(t_list *stack, int size_tocheck);
int	    check_rev_sort(t_list *stack, int size_tocheck);
void	print_stack(t_list *sa, t_list *sb);
int		max_val(t_list *stack);
int		min_val(t_list *stack);
int		mid_val(t_list *stack);
int		find_position(t_list *stack, int elm);
int		*stack_to_arr(t_list *stack);
void	fast_sort(int *tab, t_list *stack);
void	get_idx(t_list **stack);
t_list	*stack_dup(t_list *src, int size);
int	    find_f_s(t_list *stack, int to_cmp);
int	    find_l_s(t_list *stack, int to_cmp);
void	send_small(t_list **sa, t_list **sb, int med);
int	    find_next_idx(t_list *stack);
int	    find_prev_idx(t_list *stack);

#endif