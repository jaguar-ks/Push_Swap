/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 02:48:01 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/10 05:34:34 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

t_acts	*what_is_the_cost(t_list *sta, t_list *stb, int cntt)
{
	t_acts	*cost;
	t_list	*tmp;

	cost = (t_acts *)malloc(sizeof(t_acts));
	cost->rm_b = to_the_top_by_r(stb, cntt);
	cost->rrm_b = to_the_top_by_rr(stb, cntt);
	if (cost->rm_b <= cost->rrm_b)
		cost->rrm_b = 0;
	else
		cost->rm_b = 0;
	tmp = move_to_val(stb, cntt);
	cost->rm_a = align_by_r(sta, tmp->idx);
	cost->rrm_a = align_by_rr(sta, tmp->idx);
	if (cost->rm_a <= cost->rrm_a)
		cost->rrm_a = 0;
	else
		cost->rm_a = 0;
	return (cost);
}

int	find_cheapest_cost(t_list *sta, t_list *stb)
{
	t_list	*tmp;
	t_acts	*cost;
	int		chp;
	int		sm;

	tmp = stb;
	chp = 1000000;
	while (tmp)
	{
		cost = what_is_the_cost(sta, stb, tmp->content);
		sm = cost->rm_a + cost->rrm_a + cost->rm_b + cost->rrm_b;
		if (sm < chp)
			chp = sm;
		tmp = tmp->next;
		free(cost);
	}
	return (chp);
}

void	do_r_op(t_list **sta, t_list **stb, t_acts *cost)
{
	if (cost->rm_a || cost->rm_b)
	{
		while (cost->rm_a && cost->rm_b)
		{
			rr(sta, stb);
			cost->rm_a--;
			cost->rm_b--;
		}
		while (cost->rm_a)
		{
			ra(sta, 'a');
			cost->rm_a--;
		}
		while (cost->rm_b)
		{
			ra(stb, 'b');
			cost->rm_b--;
		}
	}
}

void	do_rr_op(t_list **sta, t_list **stb, t_acts *cost)
{
	if (cost->rrm_a || cost->rrm_b)
	{
		while (cost->rrm_a && cost->rrm_b)
		{
			rrr(sta, stb);
			cost->rrm_a--;
			cost->rrm_b--;
		}
		while (cost->rrm_a)
		{
			rra(sta, 'a');
			cost->rrm_a--;
		}
		while (cost->rrm_b)
		{
			rra(stb, 'b');
			cost->rrm_b--;
		}
	}
}

void	send_b_to_a(t_list **sta, t_list **stb)
{
	t_acts	*cost;
	t_list	*tb;
	int		cst;
	int		sm;

	while (*stb)
	{
		tb = (*stb);
		cst = find_cheapest_cost(*sta, *stb);
		while (tb)
		{
			cost = what_is_the_cost(*sta, *stb, tb->content);
			sm = cost->rm_a + cost->rrm_a + cost->rm_b + cost->rrm_b;
			if (sm == cst)
				break ;
			tb = tb->next;
			free(cost);
		}
		do_r_op(sta, stb, cost);
		do_rr_op(sta, stb, cost);
		pa(stb, sta, 'a');
		free(cost);
	}
}
