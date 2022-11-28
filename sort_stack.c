/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:46:59 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/28 23:16:49 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_sort(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
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
	int	max;

	max = max_val(stack);
	if (stack->content == max)
		ra(stack, c);
	else if (stack->next->content == max)
		rra(stack, c);
	if (ft_lstlast(stack)->content == max)
	{
		if (!check_sort(stack))
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
	if (check_sort(stack_a))
		return ;
	if (ft_lstsize(stack_a) == 2)
		sort_two(stack_a, 'a');
	if (ft_lstsize(stack_a) == 3)
		sort_three(stack_a, 'a');
}
