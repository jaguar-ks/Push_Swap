/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:08:18 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/29 01:58:03 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

	dup = stack_dup(stack);
	stack_fast_sort(dup);
	tab = stack_to_arr(dup);
	mid = tab[(ft_lstsize(stack) / 2) - 1];
	return (ft_lstclear(&dup), free(tab), mid);
}

int	find_position(t_list *stack, int (*f)(t_list *))
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = stack;
	while (++i < ft_lstsize(stack) && tmp)
	{
		if (tmp->content == (f)(stack))
			break ;
		tmp = tmp->next;
	}
	return (i);
}
