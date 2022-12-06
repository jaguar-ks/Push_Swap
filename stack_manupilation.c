/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manupilation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:58:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/06 05:25:21 by faksouss         ###   ########.fr       */
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

t_list	*stack_dup(t_list *src)
{
	t_list	*tmp;
	t_list	*new;
	t_list	*dst;

	tmp = src;
	dst = NULL;
	while (tmp)
	{
		new = ft_lstnew(tmp->content, tmp->idx);
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
	while (min_val(*stack_a) <= med && ft_lstsize(*stack_a))
	{
		if (check_sort(*stack_a, ft_lstsize(*stack_a)) || min_val(*stack_a) > med)
			break ;
		if ((ft_lstsize(*stack_b) && !check_rev_sort(*stack_b, 2)) || !check_sort(*stack_a, 2))
			ss(*stack_a, *stack_b);
		if (find_position(*stack_a, min_val(*stack_a)) >= find_l_s(*stack_a, med))
		{
			while (find_position(*stack_a, min_val(*stack_a)))
				rra(stack_a, 'a');
		}
		else if (find_f_s(*stack_a, med) < ft_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->content > med)
				ra(stack_a, 'a');
		}
		else if(find_l_s(*stack_a, med) > ft_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->content > med)
				rra(stack_a, 'a');
		}
		pa(stack_a, stack_b, 'b');
	}
}

// void	send_big(t_list **stack_a, t_list **stack_b, int med)
// {
// 	int	rm;
// 	int	rrm;
// 	if (!*stack_a)
// 		return ;
// 	while (max_val(*stack_a) >= med)
// 	{
// 		if (max_val(*stack_a) < med)
// 			break ;
// 		// if ((*stack_b)->content > (*stack_b)->next->content)
// 		// 	ss(*stack_b, *stack_a);
// 		if (find_f_b(*stack_a, med) < ft_lstsize(*stack_a) / 2 || rm > 0)
// 			do_r_op(stack_b, stack_a, rm, find_f_b(*stack_a, med));
// 		else if(find_l_b(*stack_a, med) >= ft_lstsize(*stack_a) / 2 || rrm > 0)
// 			do_rr_op(stack_b, stack_a, find_f_b(*stack_b, mid_val(*stack_b)), find_l_b(*stack_a, med));
// 		pa(stack_a, stack_b, 'a');
// 	}
// 	// print_stack(*stack_b, *stack_a);
// 	// sleep(1);
// }

void	send_and_put_in_place(t_list **sta, t_list **stb, int med)
{
	int		*tab;

	while (max_val(*stb, ft_lstsize(*stb)) >= med)
	{
		// if (max_val(*stb) < med)
 		// 	break ;
		tab = stack_to_arr(*sta);
		fast_sort(tab, *sta);
		get_idx(sta, tab);
		if (find_f_b(*stb, med) < ft_lstsize(*stb) / 2 || (*sta)->idx != (*sta)->next->idx - 1)
		{
			while ((*stb)->content < med || ((*sta)->idx + 1 != (*sta)->next->idx))
			{
				if ((*sta)->idx + 1 == (*sta)->next->idx && (*stb)->content < med)
					ra(stb, 'b');
				else if ((*sta)->idx + 1 != (*sta)->next->idx && (*stb)->content < med)
				{
					if ((*sta)->idx + 1 != (*sta)->next->idx)
						ss(*sta, *stb);
					if ((*sta)->idx + 1 != (*sta)->next->idx)
						rr(sta, stb);
				}
				else if ((*sta)->idx + 1 != (*sta)->next->idx && (*stb)->content >= med)
				{
					if ((*sta)->idx + 1 != (*sta)->next->idx)
						sa(*sta, 'a');
					if ((*sta)->idx + 1 != (*sta)->next->idx)
						ra(sta, 'a');
				}
				// else
				// 	break ;
				//print_stack(*sta, *stb);
				// ft_printf("|%d|%d|%d|%d|\n", (*stb)->content, med, (*sta)->idx, (*sta)->next->idx);
			}
		}
		if (find_l_b(*stb, med) > ft_lstsize(*stb) / 2 || !check_sort(*sta, ft_lstsize(*sta)))
		{
			while ((*stb)->content < med || (!check_sort(*sta, ft_lstsize(*sta)) && ft_lstlast(*sta)->content == max_val(*sta, ft_lstsize(*sta))))
			{
				if (ft_lstlast(*sta)->content == max_val(*sta, ft_lstsize(*sta)) && (check_sort(*sta, ft_lstsize(*sta)) && (*stb)->content < med))
					rra(stb, 'b');
				else if (ft_lstlast(*sta)->content != max_val(*sta, ft_lstsize(*sta)) && (!check_sort(*sta, ft_lstsize(*sta)) && (*stb)->content < med))
				{
					if ((*sta)->idx > (*sta)->next->idx)
						ss(*sta, *stb);
					if (ft_lstlast(*sta)->content != max_val(*sta, ft_lstsize(*sta)) && !check_sort(*sta, ft_lstsize(*sta)))
						rrr(sta, stb);
				}
				else if (ft_lstlast(*sta)->content != max_val(*sta, ft_lstsize(*sta)) && (*stb)->content > med)
				{
					if ((*sta)->idx > (*sta)->next->idx)
						sa(*sta, 'a');
					if (ft_lstlast(*sta)->content != max_val(*sta, ft_lstsize(*sta)) && !check_sort(*sta, ft_lstsize(*sta)))
						rra(sta, 'a');
				}
			}
		}
		pa(stb, sta, 'a');
		tab = stack_to_arr(*sta);
		fast_sort(tab, *sta);
		get_idx(sta, tab);
	}
}

void	finish_it(t_list **stack)
{
	while ((*stack)->idx + 1 != (*stack)->next->idx)
	{
		if ((*stack)->idx + 1 != (*stack)->next->idx)
			sa(*stack, 'a');
		if ((*stack)->idx + 1 != (*stack)->next->idx)
			ra(stack, 'a');
	}
	while (ft_lstlast(*stack)->content != max_val(*stack, ft_lstsize(*stack)))
	{
		if ((*stack)->idx + 1 != (*stack)->next->idx)
			sa(*stack, 'a');
		rra(stack, 'a');
	}
	// print_stack(*stack, NULL);
}
