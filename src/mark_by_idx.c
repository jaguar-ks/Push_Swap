/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_by_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:50:36 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/08 09:59:51 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

t_list	*move_to_idx(t_list *st, int idx)
{
	t_list	*tmp;

	tmp = st;
	while (tmp && tmp->idx != idx)
		tmp = tmp->next;
	return (tmp);
}

void	mark_by_idx(t_list **sta, t_list *m_h)
{
	t_list	*tmp;
	int		idx;

	reset_marks(sta);
	tmp = (*sta);
	idx = m_h->idx;
	tmp = move_to_idx(*sta, idx);
	tmp->st = 1;
	if (tmp == ft_lstlast(*sta))
		tmp = (*sta);
	else
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->st)
			break ;
		tmp->st = (idx < tmp->idx);
		if (tmp->st)
			idx = tmp->idx;
		if (tmp == ft_lstlast(*sta))
			tmp = (*sta);
		else
			tmp = tmp->next;
	}
}
