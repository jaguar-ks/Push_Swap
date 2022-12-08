/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manupilation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:58:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/08 05:29:12 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*stack_to_arr(t_list *stack)
{
	int		i;
	int		*tab;
	t_list	*tmp;

	tab = (int *)malloc(sizeof(int) * ft_lstsize(stack));
	if (!tab)
		return (NULL);
	i = -1;
	tmp = stack;
	while (++i < ft_lstsize(stack))
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
	}
	return (tab);
}

void	fast_sort(int *tab, t_list *stack)
{
	int	i;
	int	j;
	int	mv;

	i = -1;
	while (++i < ft_lstsize(stack))
	{
		j = i;
		while (++j < ft_lstsize(stack))
		{
			if (tab[i] > tab[j])
			{
				mv = tab[i];
				tab[i] = tab[j];
				tab[j] = mv;
			}
		}
	}
}

t_list	*stack_dup(t_list *src, int size)
{
	t_list	*tmp;
	t_list	*new;
	t_list	*dst;
	int		i;

	tmp = src;
	dst = NULL;
	i = -1;
	while (tmp && ++i < size)
	{
		new = ft_lstnew(tmp->content, tmp->idx);
		ft_lstadd_back(&dst, new);
		tmp = tmp->next;
	}
	return (dst);
}

void	get_idx(t_list **stack)
{
	int		i;
	int		*tab;
	t_list	*tmp;

	i = -1;
	tab = stack_to_arr(*stack);
	fast_sort(tab, *stack);
	while (++i < ft_lstsize(*stack))
	{
		tmp = (*stack);
		while (tmp->content != tab[i])
			tmp = tmp->next;
		if (tmp->content == tab[i])
			tmp->idx = i;
	}
	free(tab);
}

void	send_small(t_list **stack_a, t_list **stack_b, int med)
{
	while (min_val(*stack_a) < med)
	{
		if ( min_val(*stack_a) >= med)
			break ;
		if ((*stack_a)->next->content <= med)
			ss(*stack_a, *stack_b);
		else if (find_f_s(*stack_a, med) <= ft_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->content > med)
				ra(stack_a, 'a');
		}
		else if(find_l_s(*stack_a, med) > ft_lstsize(*stack_a) / 2 && (*stack_a)->content > med)
		{
			while ((*stack_a)->content > med)
				rra(stack_a, 'a');
		}
		if ((*stack_a)->content <= med)
			pa(stack_a, stack_b, 'b');
		// print_stack(*stack_a, *stack_b);
	}
}
