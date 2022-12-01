/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manupilation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:58:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/01 22:41:40 by faksouss         ###   ########.fr       */
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

void	stack_fast_sort(t_list *stack)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		mv;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next)
			tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->content > tmp1->content)
			{
				mv = tmp->content;
				tmp->content = tmp1->content;
				tmp1->content = mv;
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

t_list	*stack_dup(t_list *src)
{
	t_list	*tmp;
	t_list	*new;
	t_list	*dst;

	tmp = src;
	dst = NULL;
	while (tmp)
	{
		new = ft_lstnew(tmp->content);
		ft_lstadd_back(&dst, new);
		tmp = tmp->next;
	}
	return (dst);
}

void	stack_rev(t_list *stack)
{
	t_list	*tmp;
	int		*tab;
	int		i;

	tmp = stack;
	tab = stack_to_arr(stack);
	i = ft_lstsize(stack);
	while (--i >= 0 && tmp)
	{
		tmp->content = tab[i];
		tmp = tmp->next;
	}
	free(tab);
}

void	send_small(t_list **stack_a, t_list **stack_b, int med)
{
	while (min_val(*stack_a) <= med)
	{
		if (check_sort(*stack_a, ft_lstsize(*stack_a)) || min_val(*stack_a) > med)
			break ;
		if (ft_lstsize(*stack_b) && !check_rev_sort(*stack_b, 2) && !check_sort(*stack_a, 2))
			ss(*stack_a, *stack_b);
		if (find_position(*stack_a, min_val(*stack_a)) >= find_l_s(*stack_a, med))
		{
			while (find_position(*stack_a, min_val(*stack_a)))
				rra(*stack_a, 'a');
		}
		else if (find_f_s(*stack_a, med) < ft_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->content > med)
				ra(*stack_a, 'a');
		}
		else if(find_l_s(*stack_a, med) > ft_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->content > med)
				rra(*stack_a, 'a');
		}
		pa(stack_a, stack_b, 'b');
	}
}
