/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:46:59 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/29 00:36:44 by faksouss         ###   ########.fr       */
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

void	sort_two(t_list *stack, char c)
{
	if (stack->content > stack->next->content)
		sa(stack, c);
}

void	sort_three(t_list *stack, char c)
{
	int		max;
	t_list	*tmp;

	tmp = stack;
	max = max_val(stack);
	if (tmp->content == max)
		ra(stack, c);
	else if (tmp->next->content == max)
		rra(stack, c);
	tmp = tmp->next->next;
	if (tmp->content == max)
	{
		if (!check_sort(stack, 3))
			sort_two(stack, c);
		return ;
	}
}

void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = stack_a;
	tmp1 = stack_b;
	if (check_sort(stack_a, ft_lstsize(stack_a)))
		return ;
	if (ft_lstsize(stack_a) == 2)
		sort_two(stack_a, 'a');
	if (ft_lstsize(stack_a) == 3)
		sort_three(stack_a, 'a');
}
