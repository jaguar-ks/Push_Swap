/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:08:18 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/08 06:12:46 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	find_position(t_list *stack, int elm)
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
			return (find_position(stack, tmp->content));
		tmp = tmp->next;
	}
	return (0);
}

int	find_l_s(t_list *stack, int to_cmp)
{
	int	*tab;
	int	i;

	tab = stack_to_arr(stack);
	i = ft_lstsize(stack);
	while (--i)
	{
		if (tab[i] <= to_cmp)
			return (free(tab), i);
	}
	return (free(tab), i);
}
