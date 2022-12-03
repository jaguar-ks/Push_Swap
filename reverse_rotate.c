/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:48:05 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/03 17:11:49 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rra(t_list **stack, char c)
{
	int	i;
	t_list	*tmp;

	i = -1;
	if (*stack)
	{
		tmp = ft_lstlast(*stack);
		ft_lstadd_front(stack, ft_lstnew(tmp->content, tmp->idx));
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstdelone(tmp->next);
		tmp->next = NULL;
		tmp = NULL;
		if (c == 'a' || c == 'b')
			ft_printf("rr%c\n", c);
	}
	return ;
}

void	rrr(t_list **sa, t_list **sb)
{
	if (*sa && ft_lstsize(*sb) <= 1)
		rra(sa, 'a');
	else if (*sb && ft_lstsize(*sa) <= 1)
		rra(sb, 'b');
	else
	{
		rra(sa, 'd');
		rra(sb, 'y');
		ft_printf("rrr\n");
	}
}
