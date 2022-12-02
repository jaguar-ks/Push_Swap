/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:48:05 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/02 02:39:02 by faksouss         ###   ########.fr       */
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
	if (sa && ft_lstsize(sb) <= 1)
		rra(sa, 'a');
	else if (sb && ft_lstsize(sa) <= 1)
		rra(sb, 'b');
	else
	{
		rra(sa, 'd');
		rra(sb, 'y');
		ft_printf("rrr\n");
	}
}
