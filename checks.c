/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:01:42 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/08 06:09:52 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_dup_range(t_list *tab)
{
	t_list	*tmp;
	t_list	*cr;

	tmp = tab;
	cr = tmp->next;
	while (tmp)
	{
		cr = tmp->next;
		while (cr)
		{
			if ((tmp->content <= -2147483648 && tmp->content >= 2147483647)
				|| (tmp->content == cr->content))
				return (0);
			cr = cr->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_arg(char *r)
{
	int	i;

	i = -1;
	if (r[0] == '-' || r[0] == '+')
		i++;
	while (r[++i])
		if (!ft_isdigit(r[i]))
			return (0);
	return (1);
}

int	check_sort(t_list *stack, int size_tocheck)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = -1;
	while (tmp->next && ++i < size_tocheck)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_rev_sort(t_list *stack, int size_tocheck)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = -1;
	while (tmp->next && ++i < size_tocheck)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
