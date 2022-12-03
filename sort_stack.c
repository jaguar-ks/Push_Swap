/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:46:59 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/03 21:43:06 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_sort(t_list *stack, int size_tocheck)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = -1;
	while (tmp->next && ++i < size_tocheck)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_rev_sort(t_list *stack, int size_tocheck)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = -1;
	while (tmp->next && ++i < size_tocheck)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
	max = max_val(*stack, 3);
	if (tmp->content == max)
		ra(stack, c);
	else if (tmp->next->content == max)
		rra(stack, c);
	tmp = tmp->next->next;
	if (tmp->content == max)
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

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (check_sort(*stack_a, ft_lstsize(*stack_a)))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a, 'a');
	else if (ft_lstsize(*stack_a) >= 4 && ft_lstsize(*stack_a) < 7)
		sort_4_to_6(stack_a, stack_b);
}

void	sort_more(t_list **stack_a, t_list **stack_b)
{
	// int	*tab;

	while (ft_lstsize(*stack_a) > 3)
		send_small(stack_a, stack_b, mid_val(*stack_a));
	// print_stack(*stack_a, NULL);
	sort_three(stack_a, 'a');
	// print_stack(*stack_a, NULL);
	while (ft_lstsize(*stack_b) > 3)
		send_and_put_in_place(stack_a, stack_b, mid_val(*stack_b));
	// send_and_put_in_place(stack_a, stack_b, mid_val(*stack_b));
	// send_and_put_in_place(stack_a, stack_b, mid_val(*stack_b));
	print_stack(*stack_a, *stack_b);
	while (*stack_b)
	{
		pa(stack_b, stack_a, 'a');
	}
	// send_and_put_in_place(stack_a, stack_b, min_val(*stack_b));
	//print_stack(*stack_a, *stack_b);
	
}
