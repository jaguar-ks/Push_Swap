/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manupilation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:58:17 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/07 06:43:02 by faksouss         ###   ########.fr       */
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
	while (min_val(*stack_a) < med)
	{
		if ( min_val(*stack_a) >= med)
			break ;
		if ((*stack_a)->next->content <= med)
			ss(*stack_a, *stack_b);
		else if (find_f_s(*stack_a, med) <= ft_lstsize(*stack_a) / 3)
		{
			while ((*stack_a)->content > med)
				ra(stack_a, 'a');
		}
		else if(find_l_s(*stack_a, med) > ft_lstsize(*stack_a) / 3 && (*stack_a)->content > med)
		{
			while ((*stack_a)->content > med)
				rra(stack_a, 'a');
		}
		if ((*stack_a)->content <= med)
			pa(stack_a, stack_b, 'b');
		// print_stack(*stack_a, *stack_b);
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

void	execut_r(int ma, int mb, t_list **sta, t_list **stb)
{
	while (ma && mb)
	{
		rr(sta, stb);
		mb--;
		ma = ((*sta)->idx + 1 != (*sta)->next->idx);
	}
	if (ma && !mb)
	{
		while (((*sta)->idx + 1 != (*sta)->next->idx))
		{
			ra(sta, 'a');
			print_stack(*sta, *stb);
		}
	}
	else if (!ma && mb)
	{
		while (mb)
		{
			ra(stb, 'b');
			mb--;
		}
	}
}

void	execut_rr(int ma, int mb, t_list **sta, t_list **stb)
{
	while (ma && (mb < ft_lstsize(*stb)))
	{
		rrr(sta, stb);
		mb++;
		if (ft_lstlast(*sta)->idx + 1 == (*sta)->idx)
			ma = 1;
		else
			ma = 0;
	}
	if (ma && (mb >= ft_lstsize(*stb)))
	{
		while (ma)
		{
			rra(sta, 'a');
			if (ft_lstlast(*sta)->idx + 1 == (*sta)->idx)
				ma = 1;
			else
				ma = 0;
		}
	}
	else if (!ma && (mb < ft_lstsize(*stb)))
	{
		while ((mb < ft_lstsize(*stb)))
		{
			rra(stb, 'b');
			mb++;
		}
	}
}

void	send_back_align(t_list **sta, t_list **stb)
{
	int	med;

	while (ft_lstsize(*stb) > 3)
	{
		med = mid_val(*stb, ft_lstsize(*stb));
		if ((*sta)->idx - 1 == (*sta)->next->idx && (*stb)->next->content >= med)
			ss(*sta, *stb);
		if ((*sta)->idx + 1 != (*sta)->next->idx || find_f_b(*stb, med) <= ft_lstsize(*stb) / 2)
		{
			while ((*sta)->idx + 1 != (*sta)->next->idx)
				rr(sta, stb);
			while ((*stb)->content < med)
				ra(stb, 'b');
		}
		if (ft_lstlast(*sta)->idx + 1 == (*sta)->idx)
		{
			while (ft_lstlast(*sta)->idx + 1 == (*sta)->idx && find_l_b(*stb, med) > ft_lstsize(*stb) / 2)
				rrr(sta, stb);
			while (ft_lstlast(*sta)->idx + 1 == (*sta)->idx)
				rra(sta, 'a');
		}
		if ((*stb)->content >= med)
			pa(stb, sta, 'a');
		// sleep(1);
	}
}
