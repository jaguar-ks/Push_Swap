/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:08:18 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/30 08:09:41 by faksouss         ###   ########.fr       */
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

int	find_pst_of_elm(t_list *stack, int elm)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = stack;
	while (++i < ft_lstsize(stack) && tmp)
	{
		if (tmp->content == elm)
			break ;
		tmp = tmp->next;
	}
	return (i);
}

int	find_f_s(t_list *stack, int to_cmp)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->content <= to_cmp)
			return (find_pst_of_elm(stack, tmp->content));
		tmp = tmp->next;
	}
	return (0);
}

int	find_l_s(t_list *stack, int to_cmp)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		ps;

	stack_rev(stack);
	tmp = stack_dup(stack);
	stack_rev(stack);
	ps = 0;
	tmp1 = tmp;
	while (tmp)
	{
		if (tmp->content <= to_cmp)
		{
			ps = find_pst_of_elm(stack, tmp->content);
			return (ft_lstclear(&tmp1), ps);
		}
		ps++;
		tmp = tmp->next;
	}
	return (0);
}
