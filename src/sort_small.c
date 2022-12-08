/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:46:59 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/08 06:26:20 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	sort_two(t_list **stack, char c)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(*stack, c);
}

void	rev_sort_two(t_list **stack, char c)
{
	if ((*stack)->content < (*stack)->next->content)
		sa(*stack, c);
}

void	sort_three(t_list **stack, char c)
{
	int		max;
	t_list	*tmp;

	tmp = *stack;
	max = max_val(*stack);
	if (tmp->content == max)
		ra(stack, c);
	else if (tmp->next->content == max)
		rra(stack, c);
	if (ft_lstlast(tmp)->content == max)
	{
		sort_two(stack, c);
		return ;
	}
}

void	rev_sort_three(t_list **stack, char c)
{
	int		min;
	t_list	*tmp;

	tmp = *stack;
	min = min_val(*stack);
	if (tmp->content == min)
		ra(stack, c);
	else if (tmp->next->content == min)
		rra(stack, c);
	tmp = tmp->next->next;
	if (tmp->content == min)
	{
		rev_sort_two(stack, c);
		return ;
	}
}

void	sort_4_to_6(t_list **sa, t_list **sb)
{
	send_small(sa, sb, mid_val(*sa));
	if (ft_lstsize(*sa) == 2)
		sort_two(sa, 'a');
	else if (ft_lstsize(*sa) == 3)
		sort_three(sa, 'a');
	if (ft_lstsize(*sb) == 2)
		rev_sort_two(sb, 'b');
	else if (ft_lstsize(*sb) == 3)
		rev_sort_three(sb, 'b');
	while (*sb)
		pa(sb, sa, 'a');
}
