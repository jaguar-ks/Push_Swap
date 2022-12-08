/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:12:02 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/08 06:12:57 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	find_next_idx(t_list *stack)
{
	int		ps;
	t_list	*tmp;

	ps = 0;
	tmp = stack->next;
	while (tmp)
	{
		if (stack->idx == tmp->idx - 1)
			return (ps);
		ps++;
		tmp = tmp->next;
	}
	return (0);
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
