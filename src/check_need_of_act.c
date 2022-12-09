/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_need_of_act.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:01:42 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/09 01:36:27 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	check_to_push(t_list *st)
{
	t_list	*tmp;

	tmp = st;
	while (tmp)
	{
		if (!tmp->st)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sa_need(t_list *st, void (*f)(t_list **, t_list *))
{
	t_list	*swpd;

	swpd = stack_dup(st, ft_lstsize(st));
	sa(swpd, 'l');
	find_best_mark(&swpd, f);
	if (count_to_stay(swpd) > count_to_stay(st))
		return (ft_lstclear(&swpd), 1);
	else
		return (ft_lstclear(&swpd), 0);
}
