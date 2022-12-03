/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:50:06 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/03 01:06:39 by faksouss         ###   ########.fr       */
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
void	sort_stack(t_list *stack_a, t_list *stack_b);
int		check_sort(t_list *stack, int size_tocheck);
int	    check_rev_sort(t_list *stack, int size_tocheck);
void	print_stack(t_list *sa, t_list *sb);
int		max_val(t_list *stack);
int		min_val(t_list *stack);
int		mid_val(t_list *stack);
int		find_position(t_list *stack, int elm);
int		*stack_to_arr(t_list *stack);
void	fast_sort(int *tab, t_list *stack);
void	get_idx(t_list **stack, int *tab);
t_list	*stack_dup(t_list *src);
void	stack_rev(t_list *stack);
int	    find_f_s(t_list *stack, int to_cmp);
int	    find_l_s(t_list *stack, int to_cmp);
int	    find_f_b(t_list *stack, int to_cmp);
int	    find_l_b(t_list *stack, int to_cmp);
int 	find_prb(t_list *stack);
int	    how_many_rr(t_list *stack, int ps);
int	    how_many_r(int ps);
void	send_small(t_list **sa, t_list **sb, int med);
void	send_big(t_list **stack_a, t_list **stack_b, int med);
void	sort_more(t_list **stack_a, t_list **stack_b);
void	do_r_op(t_list **sta, t_list **stb, int i, int j);
void	do_rr_op(t_list **sta, t_list **stb, int i, int j);

#endif