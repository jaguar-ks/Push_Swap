/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:47:00 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/11 10:09:35 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	ra_ch(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		tmp = (*stack);
		ft_lstadd_back(stack, ft_lstnew(tmp->content, tmp->idx));
		(*stack) = (*stack)->next;
		ft_lstdelone(tmp);
	}
	return ;
}

void	rr_ch(t_list **sa, t_list **sb)
{
	if (*sa && ft_lstsize(*sb) <= 1)
		ra_ch(sa);
	else if (*sb && ft_lstsize(*sa) <= 1)
		ra_ch(sb);
	else
	{
		ra_ch(sa);
		ra_ch(sb);
	}
}
