/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:06:21 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/10 03:17:20 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	finish_sort(t_list **sta)
{
	int	i;

	i = 2;
	while (i < ft_lstsize(*sta))
	{
		if (!check_sort(*sta, i))
			break ;
		i++;
	}
	if (i <= ft_lstsize(*sta))
	{
		while (!check_sort(*sta, ft_lstsize(*sta)))
			ra(sta, 'a');
	}
	if (i > ft_lstsize(*sta))
	{
		while (!check_sort(*sta, ft_lstsize(*sta)))
			rra(sta, 'a');
	}
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	if (check_sort(*stack_a, ft_lstsize(*stack_a)))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a, 'a');
	else if (ft_lstsize(*stack_a) >= 4 && ft_lstsize(*stack_a) < 7)
		sort_4_to_6(stack_a, stack_b);
}

void	sort_by_val(t_list **sta, t_list **stb)
{
	get_idx(sta);
	find_best_mark(sta, &mark_by_val);
	send_a_to_b(sta, stb, &mark_by_val);
	send_b_to_a(sta, stb);
	finish_sort(sta);
}
