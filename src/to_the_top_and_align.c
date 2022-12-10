/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_the_top_and_align.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:36:28 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/10 01:53:08 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	to_the_top_by_r(t_list *st, int cntt)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_dup(st, ft_lstsize(st));
	while (tmp->content != cntt)
	{
		ra(&tmp, 'd');
		i++;
	}
	return (ft_lstclear(&tmp), i);
}

int	to_the_top_by_rr(t_list *st, int cntt)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_dup(st, ft_lstsize(st));
	while (tmp->content != cntt)
	{
		rra(&tmp, 'd');
		i++;
	}
	return (ft_lstclear(&tmp), i);
}

int	align_by_r(t_list *st, int idx)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_dup(st, ft_lstsize(st));
	while (tmp->idx != find_next_idx(tmp, idx))
	{
		ra(&tmp, 'd');
		i++;
	}
	return (ft_lstclear(&tmp), i);
}

int	align_by_rr(t_list *st, int idx)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_dup(st, ft_lstsize(st));
	while (tmp->idx != find_next_idx(tmp, idx))
	{
		rra(&tmp, 'd');
		i++;
	}
	return (ft_lstclear(&tmp), i);
}
