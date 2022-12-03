/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:47:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/03 01:01:30 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ra(t_list **stack, char c)
{
	t_list	*tmp;

	if (*stack)
	{
		tmp = (*stack);
		ft_lstadd_back(stack, ft_lstnew(tmp->content, tmp->idx));
		(*stack) = (*stack)->next;
		ft_lstdelone(tmp);
		if (c == 'a' || c == 'b')
			ft_printf("r%c\n", c);
	}
	return ;
}

void	rr(t_list **sa, t_list **sb)
{
	if (*sa && ft_lstsize(*sb) <= 1)
		ra(sa, 'a');
	else if (*sb && ft_lstsize(*sa) <= 1)
		ra(sb, 'b');
	else
	{
		ra(sa, 'o');
		ra(sb, 'o');
		ft_printf("rr\n");
	}
}
