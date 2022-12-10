/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:12:02 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/10 01:53:44 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	find_next_idx(t_list *stack, int idx)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (idx + 1 == tmp->idx)
			break ;
		else if (!tmp->next)
		{
			idx++;
			tmp = stack;
		}
		else
			tmp = tmp->next;
	}
	return (tmp->idx);
}

int	find_prev_idx(t_list *stack)
{
	int		ps;
	t_list	*tmp;

	ps = 0;
	tmp = stack->next;
	while (tmp)
	{
		if (stack->idx == tmp->idx + 1)
			return (ps);
		ps++;
		tmp = tmp->next;
	}
	return (0);
}
