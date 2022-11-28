/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:46:11 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/28 00:52:10 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_list *stack, char c)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	else
		return ;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a, 's');
	sa(stack_b, 's');
	ft_printf("ss\n");
}