/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:46:11 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/02 23:06:35 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_list *stack, char c)
{
	int	tmp;
	int	im;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
		im = stack->next->idx;
		stack->next->idx = stack->idx;
		stack->idx = im;
	}
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	else
		return ;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && (!stack_b || ft_lstsize(stack_b) == 1))
		sa(stack_a, 'a');
	else if (stack_b && (!stack_a || ft_lstsize(stack_a) == 1))
		sa(stack_b, 'b');
	else if (stack_a && stack_b)
	{
		sa(stack_a, 's');
		sa(stack_b, 's');
		ft_printf("ss\n");
	}
}
