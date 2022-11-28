/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:48:05 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/28 05:40:06 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rra(t_list *stack, char c)
{
	int	i;

	i = -1;
	if (stack)
	{
		while (++i < ft_lstsize(stack) - 1)
			ra(stack, 'r');
		if (c == 'a' || c == 'b')
			ft_printf("rr%c\n", c);
	}
	return ;
}

void	rrr(t_list *sa, t_list *sb)
{
	rra(sa, 'd');
	rra(sb, 'd');
	ft_printf("rrr\n");
}
