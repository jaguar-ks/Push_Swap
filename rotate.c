/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:47:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/28 00:37:36 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ra(t_list **stack, char c)
{
	t_list	*tmp;

	tmp = NULL;
	if (stack)
	{
		if (*stack)
		{
			ft_lstadd_back(stack, ft_lstnew((*stack)->content));
			if ((*stack)->next)
				tmp = (*stack)->next;
			ft_lstdelone(*stack);
			*stack = tmp;
			if (c == 'a' || c == 'b')
				ft_printf("r%c\n", c);
		}
	}
	return ;
}

void	rr(t_list **sa, t_list **sb)
{
	ra(sa, 's');
	ra(sb, 's');
	ft_printf("rr\n");
}
