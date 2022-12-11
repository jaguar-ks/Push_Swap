/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_by_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:01:56 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/11 11:03:12 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	reset_marks(t_list **st)
{
	t_list	*tmp;

	tmp = (*st);
	while (tmp)
	{
		tmp->st = 0;
		tmp = tmp->next;
	}
}

t_list	*move_to_val(t_list *st, int cnt)
{
	t_list	*tmp;

	tmp = st;
	while (tmp && tmp->content != cnt)
		tmp = tmp->next;
	return (tmp);
}

t_list	*move_to_idx(t_list *st, int idx)
{
	t_list	*tmp;

	tmp = st;
	while (tmp && tmp->idx != idx)
		tmp = tmp->next;
	return (tmp);
}

void	mark_by_val(t_list **sta, t_list *m_h)
{
	t_list	*tmp;
	int		cnt;

	reset_marks(sta);
	tmp = (*sta);
	cnt = m_h->content;
	tmp = move_to_val(*sta, cnt);
	tmp->st = 1;
	if (tmp == ft_lstlast(*sta))
		tmp = (*sta);
	else
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->st)
			break ;
		tmp->st = (cnt < tmp->content);
		if (tmp->st)
			cnt = tmp->content;
		if (tmp == ft_lstlast(*sta))
			tmp = (*sta);
		else
			tmp = tmp->next;
	}
}

int	count_to_stay(t_list *st)
{
	t_list	*tmp;
	int		i;

	tmp = st;
	i = 0;
	while (tmp)
	{
		if (tmp->st)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
