/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:47:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/30 04:04:27 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ra(t_list *stack, char c)
{
	t_list	*tmp;
	long	m;

	tmp = NULL;
	m = 0;
	if (stack)
	{
		m = stack->content;
		tmp = stack;
		while (tmp->next)
		{
			tmp->content = tmp->next->content;
			tmp = tmp->next;
		}
		tmp->content = m;
		if (c == 'a' || c == 'b')
			ft_printf("r%c\n", c);
	}
	return ;
}

void	rr(t_list *sa, t_list *sb)
{
	if (sa && (!sb || ft_lstsize(sb) < 2))
		ra(sa, 'a');
	else if (sb && (!sa || ft_lstsize(sa) < 2))
		ra(sb, 'b');
	else if (sa && sb)
	{
		ra(sa, 'o');
		ra(sb, 'o');
		ft_printf("rr\n");
	}
}
