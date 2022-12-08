/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:10:48 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/08 06:26:20 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	max_val(t_list *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	min_val(t_list *stack)
{
	int		min;
	t_list	*tmp;

	tmp = stack;
	min = max_val(stack);
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	mid_val(t_list *stack)
{
	int		mid;
	int		*tab;
	t_list	*dup;

	dup = stack_dup(stack, ft_lstsize(stack));
	tab = stack_to_arr(dup);
	fast_sort(tab, dup);
	mid = tab[(ft_lstsize(dup) / 2) - 1];
	return (ft_lstclear(&dup), free(tab), mid);
}
