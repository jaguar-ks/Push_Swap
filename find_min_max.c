/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:08:18 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/07 21:09:03 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	max_val(t_list *stack, int size)
{
	int		max;
	t_list	*tmp;
	int i = -1;

	tmp = stack;
	max = INT_MIN;
	while (tmp && ++i < size)
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
	min = max_val(stack, ft_lstsize(stack));
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	mid_val(t_list *stack, int size)
{
	int		mid;
	int		*tab;
	t_list	*dup;

	dup = stack_dup(stack, size);
	tab = stack_to_arr(dup);
	fast_sort(tab, dup);
	mid = tab[(ft_lstsize(dup) / 2) - 1];
	return (ft_lstclear(&dup), free(tab), mid);
}

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

int	find_f_b(t_list *stack, int to_cmp)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->content >= to_cmp)
			return (find_position(stack, tmp->content));
		tmp = tmp->next;
	}
	return (0);
}

int	find_l_b(t_list *stack, int to_cmp)
{
	int	*tab;
	int	i;

	tab = stack_to_arr(stack);
	i = ft_lstsize(stack);
	while (--i)
	{
		if (tab[i] >= to_cmp)
			return (free(tab), i);
	}
	return (free(tab), i);
}

int	find_prb(t_list *stack)
{
	int		ps;
	t_list	*tmp;

	ps = 0;
	tmp = stack;
	while (tmp)
	{
		if (check_sort(tmp, ft_lstsize(tmp)))
			return (tmp->content);
		ps++;
		tmp = tmp->next;
	}
	return (0);
}

void	do_r_op(t_list **sta, t_list **stb, int i, int j)
{
	while ((*sta)->content != i && j > 0)
	{
		rr(sta, stb);
		j--;
	}
	if (i > 0)
	{
		while ((*sta)->content != i)
			ra(sta, 'a');
	}
	if (j > 0)
	{
		while (j > 0)
		{
			ra(stb, 'b');
			j--;
		}
	}
}

void	do_rr_op(t_list **sta, t_list **stb, int i, int j)
{
	while (i > 0 && j > 0)
	{
		rrr(sta, stb);
		if (!check_sort((*sta)->next, ft_lstsize((*sta)->next)))
			sa(*sta, 'a');
		i--;
		j--;
	}
	if (i > 0)
	{
		while (i > 0)
		{
			if ((*sta)->content > (*sta)->next->content)
				sa(*sta, 'a');
			rra(sta, 'a');
			i--;
		}
	}
	if (j > 0)
	{
		while (j > 0)
		{
			rra(stb, 'b');
			j--;
		}
	}
}

int	find_next_idx(t_list *stack)
{
	int		ps;
	t_list	*tmp;

	ps = 0;
	tmp = stack->next;
	while (tmp)
	{
		if (stack->idx == tmp->idx - 1)
			return (ps);
		ps++;
		tmp = tmp->next;
	}
	return (0);
}

int	find_prev_idx(t_list *stack)
{
	int		ps;
	t_list	*tmp;

	ps = 0;
	tmp = stack->next;
	while (tmp)
	{
		if (stack->idx == tmp->idx + 1)
			return (ps);
		ps++;
		tmp = tmp->next;
	}
	return (0);
}
