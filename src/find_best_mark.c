/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_mark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:52:41 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/08 11:00:59 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

t_list	*max_possible_to_st(t_list **st)
{
	t_list	*tmp;
	int		max;

	max = (*st)->st_cnt;
	tmp = (*st)->next;
	while (tmp)
	{
		if (tmp->st_cnt > max)
			max = tmp->st_cnt;
		tmp = tmp->next;
	}
	tmp = *st;
	while (tmp->st_cnt != max)
		tmp = tmp->next;
	return (tmp);
}

t_list	*best_to_st(t_list **st)
{
	t_list	*tmp;
	t_list	*max;
	t_list	*t;
	int		idx;

	max = max_possible_to_st(st);
	tmp = *st;
	while (tmp)
	{
		if (tmp->st_cnt == max->st_cnt)
		{
			t = tmp;
			idx = tmp->idx;
			while (t)
			{
				if (t->st_cnt == max->st_cnt && t->idx < idx)
					idx = t->idx;
				t = t->next;
			}
			return (move_to_idx(*st, idx));
		}
		tmp = tmp->next;
	}
	return (max);
}

void	find_best_mark(t_list **st, void (*f)(t_list **, t_list *))
{
	t_list	*tmp;

	tmp = (*st);
	while (tmp)
	{
		(f)(st, tmp);
		tmp->st_cnt = count_to_stay(*st);
		tmp = tmp->next;
	}
	tmp = best_to_st(st);
	(f)(st, tmp);
}
