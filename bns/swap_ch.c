/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:46:11 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/11 10:09:15 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	sa_ch(t_list *stack)
{
	int	cnt;
	int	im;

	if (stack && stack->next)
	{
		cnt = stack->content;
		stack->content = stack->next->content;
		stack->next->content = cnt;
		im = stack->idx;
		stack->idx = stack->next->idx;
		stack->next->idx = im;
	}
	return ;
}

void	ss_ch(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && ft_lstsize(stack_b) <= 1)
		sa_ch(stack_a);
	else if (stack_b && ft_lstsize(stack_a) <= 1)
		sa_ch(stack_b);
	else if (stack_a && stack_b)
	{
		sa_ch(stack_a);
		sa_ch(stack_b);
	}
}
