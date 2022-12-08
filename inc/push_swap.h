/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:50:06 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/08 11:00:14 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libtool/libft.h"
//parssing
t_list	*take_stack(int ac, char **av);
//actions
void	sa(t_list *stack, char c);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **a, t_list **b, char c);
void	ra(t_list **stack, char c);
void	rr(t_list **sa, t_list **sb);
void	rra(t_list **stack, char c);
void	rrr(t_list **sa, t_list **sb);
//sort small numbers
void	sort_two(t_list **stack, char c);
void	rev_sort_two(t_list **stack, char c);
void	rev_sort_three(t_list **stack, char c);
void	sort_three(t_list **stack, char c);
void	sort_4_to_6(t_list **sa, t_list **sb);
void	sort_small(t_list **stack_a, t_list **stack_b);
//checks
int		check_dup_range(t_list *tab);
int		check_arg(char *r);
int		check_sort(t_list *stack, int size_tocheck);
int		check_rev_sort(t_list *stack, int size_tocheck);
//print stack content index and size
void	print_stack(t_list *sa, t_list *sb);
//find max min and med valeurs
int		max_val(t_list *stack);
int		min_val(t_list *stack);
int		mid_val(t_list *stack);
//find position
int		find_position(t_list *stack, int elm);
//manipulations of the stack
int		*stack_to_arr(t_list *stack);
void	fast_sort(int *tab, t_list *stack);
void	get_idx(t_list **stack);
t_list	*stack_dup(t_list *src, int size);
t_list	*move_to_val(t_list *st, int cnt);
t_list	*move_to_idx(t_list *st, int idx);
//find position of some elements
int		find_f_s(t_list *stack, int to_cmp);
int		find_l_s(t_list *stack, int to_cmp);
//send small elements (below med valeur) to stack B
void	send_small(t_list **sa, t_list **sb, int med);
//find position of indexs
int		find_next_idx(t_list *stack);
int		find_prev_idx(t_list *stack);
//mark functions
void	reset_marks(t_list **st);
void	mark_by_val(t_list **sta, t_list *m_h);
void	mark_by_idx(t_list **sta, t_list *m_h);
int		count_to_stay(t_list *st);
t_list	*max_possible_to_st(t_list **st);
t_list	*best_to_st(t_list **st);
void	find_best_mark(t_list **st, void (*f)(t_list **, t_list *));

#endif