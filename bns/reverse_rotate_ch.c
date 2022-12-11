/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:48:05 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/11 10:10:13 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	rra_ch(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		tmp = ft_lstlast(*stack);
		ft_lstadd_front(stack, ft_lstnew(tmp->content, tmp->idx));
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstdelone(tmp->next);
		tmp->next = NULL;
		tmp = NULL;
	}
	return ;
}

void	rrr_ch(t_list **sa, t_list **sb)
{
	if (*sa && ft_lstsize(*sb) <= 1)
		rra_ch(sa);
	else if (*sb && ft_lstsize(*sa) <= 1)
		rra_ch(sb);
	else
	{
		rra_ch(sa);
		rra_ch(sb);
	}
}
