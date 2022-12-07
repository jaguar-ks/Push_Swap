/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move_needed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:31:15 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/07 00:22:15 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	how_many_r(int ps)
{
	int		mv;

	mv = 0;
	while (ps >= 0)
	{
		mv++;
		ps--;
	}
	return (mv);
}

int	how_many_rr(t_list *stack, int ps)
{
	int		mv;

	mv = 0;
	while (ps < ft_lstsize(stack))
	{
		mv++;
		ps++;
	}
	return (mv);
}

void	mark_mode_1(t_list **stack, int cntt)
{
	t_list	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		if (tmp->content == cntt)
			break ;
		else
			tmp = tmp->next;
	}
	tmp = tmp->next;
	while (tmp)
	{
		if (cntt > tmp->content && tmp->content < tmp->next->content)
			tmp->st = 1;
		else
			tmp->st = 0;
		if (!tmp->next)
			tmp = (*stack);
		tmp = tmp->next;
	}
}

void	mark_by_idx(t_list **stack)
{
	t_list	*tmp;
	int		idx;

	tmp = (*stack);
	idx = tmp->idx;
	while (tmp->next)
	{
		if (tmp->idx == idx + 1)
		{
			tmp->st = 1;
			idx++;
		}
		tmp = tmp->next;
	}
}

int	how_many_to_stay(t_list *stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->st)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	best_to_stay(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = tmp->st_cnt;
	while (tmp->next)
	{
		if (tmp->st_cnt < tmp->next->st_cnt)
			max = tmp->next->st_cnt;
		tmp = tmp->next;
	}
	return (max);
}

int	push_or_not(t_list *stk)
{
	t_list	*tmp;

	tmp = stk;
	while (tmp)
	{
		if (!tmp->st)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	send_a_to_b(t_list **sta, t_list **stb, int cntt)
{
	(void)cntt;
	mark_by_idx(sta);
	while (push_or_not(*sta))
	{
		if (!(*sta)->st)
			pa(sta, stb, 'b');
		else
			ra(sta, 'a');
		mark_by_idx(sta);
	}
}
