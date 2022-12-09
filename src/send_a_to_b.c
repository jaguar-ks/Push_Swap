/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:50:49 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/09 02:02:32 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	recover_st(t_list **st, t_list *svd)
{
	t_list	*tsv;
	t_list	*tst;

	tst = *st;
	while (tst)
	{
		tsv = svd;
		while (tsv)
		{
			if (tsv->content == tst->content)
				tst->st = tsv->st;
			tsv = tsv->next;
		}
		tst = tst->next;
	}
}

void	send_a_to_b(t_list **sta, t_list **stb, void (*f)(t_list **, t_list *))
{
	t_list	*rec;

	while (check_to_push(*sta))
	{
		rec = stack_dup(*sta, ft_lstsize(*sta));
		if (check_sa_need(*sta, f))
		{
			sa(*sta, 'a');
			find_best_mark(sta, f);
		}
		else if (!(*sta)->st)
			pa(sta, stb, 'b');
		else
		{
			ra(sta, 'a');
			recover_st(sta, rec);
		}
		ft_lstclear(&rec);
	}
}
